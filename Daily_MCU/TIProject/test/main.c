#include <ti/drivers/PIN.h>
#include <ti/drivers/pin/PINCC26XX.h>

// ���岽��������ĸ���������
#define STEP_PIN  IOID_0
#define DIR_PIN   IOID_1
#define ENABLE_PIN IOID_2
#define MS1_PIN   IOID_3

void stepMotorInit() {
    // ��ʼ����������
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
        // �������ų�ʼ��ʧ��
        while(1);
    }

    // �������������
    PIN_setOutputValue(hStepMotorPin, ENABLE_PIN, 0);
}

// ���Ʋ��������ת����
void stepMotorRotate(int steps, int direction) {
    int i;

    // ���ò����������
    PIN_setOutputValue(hStepMotorPin, DIR_PIN, direction);

    for (i = 0; i < steps; i++) {
        // ����һ����������
        PIN_setOutputValue(hStepMotorPin, STEP_PIN, 1);
        // ��ʱһ��ʱ��
        // �������ʱʱ����Ҫ�������Ĳ��������������������
        // ������Ҫ��������͵���
        // ���磬ʹ����ʱ������ʱ����ʵ�־�ȷ�Ĳ������
        for (int j = 0; j < 1000; j++);
        PIN_setOutputValue(hStepMotorPin, STEP_PIN, 0);
        // �ٴ���ʱ
        for (int j = 0; j < 1000; j++);
    }
}

void stepMotorDemo() {
    // ��ʼ���������
    stepMotorInit();

    // ��ת���������������ת 200 ��������Ϊ��ת
    stepMotorRotate(200, 1);

    // ֹͣ�����������
    PIN_setOutputValue(hStepMotorPin, ENABLE_PIN, 1);
}

int main(void) {
    // ��ʼ������

    // ִ�в��������ʾ
    stepMotorDemo();

    // ��ѭ������

    return 0;
}
