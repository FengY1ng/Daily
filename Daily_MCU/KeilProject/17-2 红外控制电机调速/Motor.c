#include <REGX52.H>
#include "Timer1.h"

sbit Motor=P1^0;

unsigned char Counter,Compare;

void Motor_Init(void)
{
    Timer1Init();
}

void Motor_SetSpeed(unsigned char speed)
{
    Compare=speed;
}

void Timer1_Routine(void) interrupt 3
{
	TH1=0xFF;
	TL1=0x9C;
    Counter++;
    Counter%=100;
    if(Counter<Compare)
    {
        Motor=1;
    }
    else
    {
        Motor=0;
    }
}