#include <REGX52.H>

void Delay1ms(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;

    while(xms--)
    {
        i = 2;
        j = 239;
        do
        {
            while (--j);
        } while (--i);
    }
}

void main()
{
    while(1)
    {
        int i;
        for(i=0;i<8;i++)
        {
            P2=~(0x01<<i);
            Delay1ms(100);
        }
    }
}