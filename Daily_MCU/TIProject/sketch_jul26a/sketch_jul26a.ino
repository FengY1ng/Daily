#include <ti/drivers/PIN.h>
#include <ti/drivers/pin/PINCC26XX.h>

// 定义步进电机的四个控制引脚
#define STEP_PIN  IOID_0
#define DIR_PIN   IOID_1
#define ENABLE_PIN IOID_2
#define MS1_PIN   IOID_3

void stepMotorInit() {
    // 初始化引脚配置
    PIN_Config stepMotorPinCfg[] = {
        STEP_PIN    | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
        DIR_PIN     | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
        ENABLE_PIN  | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
        MS1_PIN     | PIN_GPIO_OUTPUT_EN | PIN_GPIO_LOW | PIN_PUSHPULL | PIN_DRVSTR_MAX,
        PIN_TERMINATE
    };

    PIN_Handle hStepMotorPin;
    hStepMotorPin = PIN_open(&stepMotorPinCfg);
    if (hStepMotorPin == NULL) {
        // 处理引脚初始化失败
        while(1);
    }

    // 允许步进电机驱动
    PIN_setOutputValue(hStepMotorPin, ENABLE_PIN, 0);
}

// 控制步进电机旋转步数
void stepMotorRotate(int steps, int direction) {
    int i;

    // 设置步进电机方向
    PIN_setOutputValue(hStepMotorPin, DIR_PIN, direction);

    for (i = 0; i < steps; i++) {
        // 触发一个步进脉冲
        PIN_setOutputValue(hStepMotorPin, STEP_PIN, 1);
        // 延时一段时间
        // 这里的延时时间需要根据您的步进电机和驱动器来调整
        // 可能需要进行试验和调整
        // 例如，使用延时函数或定时器来实现精确的步进间隔
        for (int j = 0; j < 1000; j++);
        PIN_setOutputValue(hStepMotorPin, STEP_PIN, 0);
        // 再次延时
        for (int j = 0; j < 1000; j++);
    }
}

void stepMotorDemo() {
    // 初始化步进电机
    stepMotorInit();

    // 旋转步进电机，例如旋转 200 步，方向为正转
    stepMotorRotate(200, 1);

    // 停止步进电机驱动
    PIN_setOutputValue(hStepMotorPin, ENABLE_PIN, 1);
}

int main(void) {
    // 初始化代码

    // 执行步进电机演示
    stepMotorDemo();

    // 主循环代码

    return 0;
}
