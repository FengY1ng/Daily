#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

unsigned char Sec;

void main()
{
	UARTInit();
	while(1)
	{
		UART_SendByte(Sec);
		Delay(1000);
		Sec++;
	}
}