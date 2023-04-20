#include <REGX52.H>

/**
 *@brief 定时器0初始化，1ms@12.000MHz
 *@param 无
 *@retval 无
 */
//STC-ISP生成的定时器
void Timer1Init(void)		//100us@12.000MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TL1 = 0x9C;		//设置定时初值
	TH1 = 0xFF;		//设置定时初值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
	ET1=1;
	EA=1;
	PT1=0;
}

//手打的定时器初始化
void Timer1_Init()
{
	//TMOD不可位寻址
//	TMOD=0x01;//0000 0001 TMOD后两位置于01将会是16位模式
	TMOD=TMOD&0x0F;//把TMOD的低4位清零，高四位保持不变
	TMOD=TMOD|0x01;//把TMOD的最低为置1，高四位保持不变

	//TCON可位寻址
	TF0=0;//溢出标志位置0，默认值应为0
	TR0=1;//定时器 T1的运行控制位。该位由软件置位和清零。

	TH0=64535/256;//高8位
	TL0=64535%256+1;//低8位，注意+1：定时器计数器是达到65536时才溢出

	ET0=1;
	EA=1;//EA为总控

	PT0=0;//PT0为0时为低优先级，为1时为高优先级
}

/*
//定时器中断程序模板
void Timer1_Routine(void) interrupt 3
{
	static unsigned int T1Count;
	//使下一次定时器仍为1ms
	TH1=0x9C;
	TL1=0xFF;

	//达到1s后执行程序
	T1Count++;
	if(T1Count>=1000)
	{
		T1Count=0;
		
	}
}
*/