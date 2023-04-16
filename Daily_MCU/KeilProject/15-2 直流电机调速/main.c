#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "Nixie.h"
#include "Key.h"

sbit Motor=P1^0;

unsigned char Counter,Compare;
unsigned char KeyNum,Speed;

void main()
{
    Timer0Init();
    Compare=50;
    while(1)
    {
        Key_Loop();
        KeyNum=Key();
        if(KeyNum==1)
        {
            Speed++;
            Speed%=4;
            if(Speed==0){Compare=0;}
            if(Speed==1){Compare=50;}
            if(Speed==2){Compare=75;}
            if(Speed==3){Compare=100;}
        }
        Nixie(1,Speed);
    }
}

void Timer0_Routine(void) interrupt 1
{
	TH0=0xFF;
	TL0=0x9C;
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