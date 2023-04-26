#include <REGX52.H>
#include "Nixie.h"
#include "Timer0.h"

void main()
{
    Timer0_Init();  
    NixieShowOwn(0,0x39);
    NixieShowNum(2,0);
    NixieShowNum(3,3);
    NixieShowNum(4,0);
    NixieShowNum(5,0);
    NixieShowNum(6,4);
    NixieShowNum(7,0);
    while(1)
    {
        NixieShowNum(1,4);
    }
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
	}
}