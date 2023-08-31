#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Serial.h"
int main (void)
{
	OLED_Init();
	Serial_Init();
	OLED_ShowString(1,1,"Cx:");
	OLED_ShowString(2,1,"Cy:");
	OLED_ShowString(3,1,"Cz:");
	while(1)
	{
		OLED_ShowNum(1,4,Cx,4);
		OLED_ShowNum(2,4,Cy,4);
		OLED_ShowNum(3,4,Cz,4);
	}

}




