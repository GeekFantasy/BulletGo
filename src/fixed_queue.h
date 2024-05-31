#ifndef FIXED_QUEUE_H
#define FIXED_QUEUE_H

#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>

template <typename T, size_t N>
class FixedQueue
{
private:
    T arr[N];
    size_t head = 0;
    size_t tail = 0;
    size_t numElements = 0;
    SemaphoreHandle_t mutex;

public:
    FixedQueue()
    {
        mutex = xSemaphoreCreateMutex();
    }

    ~FixedQueue()
    {
        vSemaphoreDelete(mutex);
    }

    bool push(const T &item)
    {
        if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE)
        {
            if (numElements >= N)
            {
                // 队列已满，删除头部元素
                head = (head + 1) % N;
                numElements--;
            }

            arr[tail] = item;
            tail = (tail + 1) % N;
            numElements++;

            xSemaphoreGive(mutex);
            return true;
        }
        else
        {
            return false; // 获取互斥锁失败
        }
    }

    T getLast() const
    {
        if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE)
        {
            if (numElements > 0)
            {
                size_t lastIndex = (tail == 0) ? (N - 1) : (tail - 1);
                
                xSemaphoreGive(mutex);
                return arr[lastIndex];
            }

            xSemaphoreGive(mutex);
        }

        return T(); // 队列为空，返回默认值
    }

    T pop()
    {
        if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE)
        {
            if (numElements == 0)
            {
                // 队列为空
                xSemaphoreGive(mutex);
                return T(); // 返回默认值
            }

            T item = arr[head];
            head = (head + 1) % N;
            numElements--;

            xSemaphoreGive(mutex);
            return item;
        }
        else
        {
            return T(); // 获取互斥锁失败
        }
    }
    size_t size() const
    {
        return numElements;
    }
    bool empty() const
    {
        return numElements == 0;
    }
    size_t getAllData(T *dataArray, size_t maxSize) const
    {
        if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE)
        {
            size_t numCopied = 0;
            size_t index = head;

            while (numCopied < numElements && numCopied < maxSize)
            {
                dataArray[numCopied] = arr[index];
                index = (index + 1) % N;
                numCopied++;
            }

            xSemaphoreGive(mutex);
            return numCopied;
        }
        else
        {
            return 0; // 获取互斥锁失败
        }
    }
};

#endif