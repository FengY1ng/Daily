#include <REGX52.H>
#include "LCD1602.h"

void Delay(unsigned int Time)		//@12.000MHz
{
	while(--Time)
	{
		unsigned char i, j;

		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}


int main()
{
	unsigned char i=0;
	LCD_Init();
	LCD_ShowString(1,1,"My edu email:");
	LCD_ShowString(2,1,"2104060804@stu.hrbust.edu.cn");
	while(1)
	{
		LCD_ShowString(1,1,"                                       ");
		LCD_WriteCommand(0x18);
		Delay(650);
		i++;
		LCD_ShowString(1,i%40+1,"My edu email:");
	}
}