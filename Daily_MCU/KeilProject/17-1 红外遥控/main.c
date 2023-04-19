#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "IR.h"

unsigned char Num;
unsigned char Address,Command;

void main()
{
    LCD_Init();
    LCD_ShowString(1,1,"A");

    IR_Init();

    while(1)
    {
        if(IR_GetDataFlag())
        {
            Address=IR_GetAddress();
            Command=IR_GetCommand();

            LCD_ShowHexNum(2,1,Address,2);
            LCD_ShowHexNum(2,5,Command,2);
        }
    }
}