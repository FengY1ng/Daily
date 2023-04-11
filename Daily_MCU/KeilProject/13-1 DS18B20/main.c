#include <REGX52.H>
#include <LCD1602.h>
#include "DS18B20.h"
#include "Delay.h"

float temperature;

void main()
{
	DS18B20_ConvertT();
	Delay(1000);
	LCD_Init();
	LCD_ShowString(1,1,"Temperature:");

	while(1)
	{
		DS18B20_ConvertT();
		temperature=DS18B20_ReadT();
		if(temperature<0)
		{
			LCD_ShowChar(2,1,'-');
			temperature=-temperature;
		}
		else
		{
			LCD_ShowChar(2,1,'+');
		}
		LCD_ShowNum(2,2,temperature,3);
		LCD_ShowChar(2,5,'.');
		LCD_ShowNum(2,6,(unsigned long)(temperature*10000)%10000,4);
	}
}
