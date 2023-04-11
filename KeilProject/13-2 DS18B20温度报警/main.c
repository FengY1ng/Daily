#include <REGX52.H>
#include "LCD1602.h"
#include "DS18B20.h"
#include "Delay.h"
#include "AT24C02.h"
#include "Key.h"
#include "Timer0.h"

float temperature,TShow;
char TLow,THigh;
unsigned char KeyNum;

void main()
{
	THigh=AT24C02_ReadByte(0);
	TLow=AT24C02_ReadByte(1);
	if(THigh>125 || TLow<-55 || THigh<=TLow)
	{
		THigh=20;
		TLow=15;
	}
	DS18B20_ConvertT();
	Delay(1000);
	LCD_Init();
	LCD_ShowString(1,1,"T:");
	LCD_ShowString(2,1,"TH:");
	LCD_ShowString(2,9,"TL:");
	LCD_ShowSignedNum(2,4,THigh,3);
	LCD_ShowSignedNum(2,12,TLow,3);
	Timer0_Init();

	while(1)
	{
		KeyNum=Key();
		//温度读取及其显示
		DS18B20_ConvertT();
		temperature=DS18B20_ReadT();
		if(temperature<0)
		{
			LCD_ShowChar(1,3,'-');
			TShow=-temperature;
		}
		else
		{
			LCD_ShowChar(1,3,'+');
			TShow=temperature;
		}
		LCD_ShowNum(1,4,TShow,3);
		LCD_ShowChar(1,7,'.');
		LCD_ShowNum(1,8,(unsigned long)(TShow*100)%100,2);
		//阈值判断及其显示
		if(KeyNum)
		{
			if(KeyNum==1)
			{
				THigh++;
				if(THigh>125)
				{
					THigh=125;
				}
			}
			if(KeyNum==2)
			{
				THigh--;
				if(THigh<=TLow)
				{
					THigh++;
				}
			}
			if(KeyNum==3)
			{
				TLow++;
				if(TLow>=THigh)
				{
					TLow--;
				}
			}
			if(KeyNum==4)
			{
				TLow--;
				if(TLow<-55)
				{
					TLow=-55;
				}
			}
			LCD_ShowSignedNum(2,4,THigh,3);
			LCD_ShowSignedNum(2,12,TLow,3);
			AT24C02_WriteByte(0,THigh);
			Delay(5);
			AT24C02_WriteByte(1,TLow);
			Delay(5);
		}
		if(temperature>THigh)
		{
			LCD_ShowString(1,13,"OV:H");
		}
		else if(temperature<TLow)
		{
			LCD_ShowString(1,13,"OV:L");
		}
		else
		{
			LCD_ShowString(1,13,"    ");
		}
	}
}

void Timer0_Routine(void) interrupt 1
{
	static unsigned int T0Count;
	//使下一次定时器仍为1ms
	TH0=0xFC;
	TL0=0x18;

	//达到1s后执行程序
	T0Count++;
	if(T0Count>=20)
	{
		T0Count=0;
		Key_Loop();
	}
}