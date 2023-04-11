#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.H>

unsigned char KeyNum,LEDMode;

void main()
{
	P2=0xFE;
	Timer0_Init();
	while(1)
	{
		 KeyNum=Key();
		 if(KeyNum)
		 {
			if(KeyNum==1)
			{
				LEDMode++;
				if(LEDMode>=2) LEDMode=0;
			}
		 }
	}
}

void Timer0_Routine(void) interrupt 1
{
	static unsigned int T0Count;
	//使下一次定时器仍为1ms
	TH0=0xFC;
	TL0=0x18;

	T0Count++;
	if(T0Count>=500)
	{
		T0Count=0;
		if(LEDMode==0)
			P2=_crol_(P2,1);
		if(LEDMode==1)
			P2=_cror_(P2,1);
	}
}