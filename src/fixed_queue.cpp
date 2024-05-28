#include "fixed_queue.h"
#include <Arduino.h>

template<typename T, size_t N>
class FixedQueue {
private:
    T arr[N];
    size_t head = 0;
    size_t tail = 0;
    size_t numElements = 0;

public:
    bool push(const T& item) {
        if (numElements >= N) {
            // 队列已满，删除头部元素
            head = (head + 1) % N;
            numElements--;
        }

        arr[tail] = item;
        tail = (tail + 1) % N;
        numElements++;

        return true;
    }

    T pop() {
        if (numElements == 0) {
            // 队列为空
            return T(); // 返回默认值
        }

        T item = arr[head];
        head = (head + 1) % N;
        numElements--;

        return item;
    }

    size_t size() const {
        return numElements;
    }

    bool empty() const {
        return numElements == 0;
    }
};