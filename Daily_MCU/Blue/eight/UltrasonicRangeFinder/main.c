#include <REGX52.H>
#include "Nixie.h"
#include "Timer0.h"

unsigned char KeyNum=0;

void main()
{
    Timer0_Init(); 
    ProcessInit();
    while(1)
    {
        KeyNum=Key();
        if(KeyNum==0)
        {
            
        }
        if(KeyNum==1)
        {

        }
        if(KeyNum==2)
        {

        }
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