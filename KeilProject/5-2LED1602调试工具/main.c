#include <REGX52.H>
#include "LCD1602.h"

int Res;

void main()
{
    LCD_Init();
    Res=1+1;
    LCD_ShowNum(1,1,Res,3);
    while (1)
    {
        
    }
    
}