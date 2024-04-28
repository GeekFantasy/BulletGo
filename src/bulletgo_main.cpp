/***************************************************
  BulletGo固件代码

  基于HoloCubic多功能固件源码开发
  https://github.com/ClimbSnail/HoloCubic_AIO
 ****************************************************/

#include "driver/lv_port_indev.h"
#include "driver/lv_port_fs.h"

#include "common.h"
#include "sys/app_controller.h"

#include "app/app_conf.h"

#include <SPIFFS.h>
#include <esp32-hal.h>
#include <esp32-hal-timer.h>


static bool isCheckAction = false;

/*** Component objects **7*/
ImuAction *act_info;           // 存放mpu6050返回的数据
AppController *app_controller; // APP控制器

TaskHandle_t handleTaskLvgl;

void TaskLvglUpdate(void *parameter)
{
    // ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    for (;;)
    {
        AIO_LVGL_OPERATE_LOCK(lv_timer_handler();)
        vTaskDelay(5);
    }
}

TimerHandle_t xTimerAction = NULL;
void actionCheckHandle(TimerHandle_t xTimer)
{
    // 标志需要检测动作
    isCheckAction = true;
}

void my_print(const char *buf)
{
    Serial.printf("%s", buf);
    Serial.flush();
}

void setup()
{
    Serial.begin(115200);

    Serial.println(F("\nBulletGo version " BULLETGO_VERSION "\n"));
    Serial.flush();
    // MAC ID可用作芯片唯一标识
    Serial.print(F("ChipID(EfuseMac): "));
    Serial.println(ESP.getEfuseMac());
    // flash运行模式
    // Serial.print(F("FlashChipMode: "));
    // Serial.println(ESP.getFlashChipMode());
    // Serial.println(F("FlashChipMode value: FM_QIO = 0, FM_QOUT = 1, FM_DIO = 2, FM_DOUT = 3, FM_FAST_READ = 4, FM_SLOW_READ = 5, FM_UNKNOWN = 255"));

    app_controller = new AppController(); // APP控制器

    // 需要放在Setup里初始化
    if (!SPIFFS.begin(true))
    {
        Serial.println("SPIFFS Mount Failed");
        return;
    }

    // config_read(NULL, &g_cfg);   // 旧的配置文件读取方式
    app_controller->read_config(&app_controller->sys_cfg);
    app_controller->read_config(&app_controller->mpu_cfg);
    app_controller->read_config(&app_controller->rgb_cfg);

    /*** Init screen ***/
    app_controller->sys_cfg.rotation = 0; // Force the rotaion to 2 
    screen.init(app_controller->sys_cfg.rotation,
                app_controller->sys_cfg.backLight);

    /*** Init micro SD-Card ***/
    tf.init();

    lv_fs_fatfs_init();

#if LV_USE_LOG
    lv_log_register_print_cb(my_print);
#endif /*LV_USE_LOG*/

    app_controller->init();

    // 将APP"安装"到controller里
#if APP_BULLET_COUNTER_USE
    app_controller->app_install(&bullet_counter_app);
#endif
#if APP_WEATHER_USE
    app_controller->app_install(&weather_app);
#endif

#if APP_GAME_2048_USE
    app_controller->app_install(&game_2048_app);
#endif

    // 自启动APP
    app_controller->app_auto_start();

    // 优先显示屏幕 加快视觉上的开机时间
    app_controller->main_process(&mpu.action_info, ButtonEvent::NONE);

    /*** Init IMU as input device ***/
    // lv_port_indev_init();

    mpu.init(app_controller->sys_cfg.mpu_order,
             app_controller->sys_cfg.auto_calibration_mpu,
             &app_controller->mpu_cfg); // 初始化比较耗时

    // 初始化按钮
    button.init();

    // 初始化Sensor
    bullet_sensor.init();

    // 先初始化一次动作数据 防空指针
    act_info = mpu.getAction();
    // 定义一个mpu6050的动作检测定时器
    xTimerAction = xTimerCreate("Action Check",
                                200 / portTICK_PERIOD_MS,
                                pdTRUE, (void *)0, actionCheckHandle);
    xTimerStart(xTimerAction, 0);
}

void loop()
{
    screen.routine();

    if (isCheckAction)
    {
        isCheckAction = false;
        act_info = mpu.getAction();
    }
    ButtonEvent event = button.getEvent();
    app_controller->main_process(act_info, event); // 运行当前进程

    Serial.printf("Time: %d \n", GET_SYS_MILLIS());

    //Read button state
    Serial.printf("Button State: %d, Event: %d \n", button.getState(), event);
    
    Serial.printf("Bullet Sensor, bullet count: %d\n", bullet_sensor.getNum());
    Serial.printf("Bullet Sensor, is loaded: %s\n", bullet_sensor.isLoaded()?"true":"false");
}