#include <REGX52.H>
#include "Delay.h"

unsigned char Key()
{
    unsigned char KeyNum=0;
    if(P3_1==0)
    {
        Delay_ms(10);
        while(P3_1==0);
        Delay_ms(10);
        KeyNum=1;
    }
    if(P3_0==0)
    {
        Delay_ms(10);
        while(P3_0==0);
        Delay_ms(10);
        KeyNum=2;
    }
    if(P3_2==0)
    {
        Delay_ms(10);
        while(P3_2==0);
        Delay_ms(10);
        KeyNum=3;
    }
    if(P3_3==0)
    {
        Delay_ms(10);
        while(P3_3==0);
        Delay_ms(10);
        KeyNum=4;
    }
    return KeyNum;
}