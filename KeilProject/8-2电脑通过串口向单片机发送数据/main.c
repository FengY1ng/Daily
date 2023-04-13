#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

void main()
{
	UARTInit();
	while(1)
	{
		
	}
}

void UART_Routine() interrupt 4
{
	if(RI==1)//!SCON寄存器需要看看
	{
		P2=SBUF;
		//一个函数不能在主函数和中断函数中同时调用。比如在主函数中正在使用Send，而在此处再次调用，那么Send函数将会被破坏
		UART_SendByte(SBUF);
		
		RI=0;
	}
}