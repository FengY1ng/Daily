#include <REGX52.H>

/**
 *@brief 串口初始化
 *@param 无
 *@retval 无
 */
void UARTInit(void)		//9600bps@11.0592MHz
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xFD;		//设定定时初值
	TH1 = 0xFD;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	EA=1;
	ES=1;
}

/**
 *@brief 串口发送一个字节数据
 *@param 一个字节数据
 *@retval 无
 */
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}

/*串口中断函数模板
void UART_Routine() interrupt 4
{
	if(RI==1)//!SCON寄存器需要看看
	{
		//一个函数不能在主函数和中断函数中同时调用。比如在主函数中正在使用Send，而在此处再次调用，那么Send函数将会被破坏

		
		RI=0;
	}
}

*/