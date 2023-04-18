#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"

sbit DA=P2^1;

unsigned char Counter,Compare;

void main()
{
    unsigned char i;
    Timer0Init();
    Compare=50;
    while(1)
    {
        for(i=0;i<100;i++)
        {
            Compare=i;
            Delay(10);
        }
        for(i=100;i>0;i--)
        {
            Compare=i;
            Delay(10);
        }
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
        DA=1;
    }
    else
    {
        DA=0;
    }
}