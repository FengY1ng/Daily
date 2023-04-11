#include <REGX52.H>

/**
 *@brief 定时器0初始化，1ms@12.000MHz
 *@param 无
 *@retval 无
 */
void Timer0Init(void)		//1毫秒@12.000MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0=1;
	EA=1;
	PT0=0;
}

// //手打的定时器初始化
// void Timer0_Init()
// {
// 	//TMOD不可位寻址
// //	TMOD=0x01;//0000 0001 TMOD后两位置于01将会是16位模式
// 	TMOD=TMOD&0xF0;//把TMOD的低4位清零，高四位保持不变
// 	TMOD=TMOD|0x01;//把TMOD的最低为置1，高四位保持不变

// 	//TCON可位寻址
// 	TF0=0;//溢出标志位置0，默认值应为0
// 	TR0=1;//定时器 T1的运行控制位。该位由软件置位和清零。

// 	TH0=64535/256;//高8位
// 	TL0=64535%256+1;//低8位，注意+1：定时器计数器是达到65536时才溢出

// 	ET0=1;
// 	EA=1;//EA为总控

// 	PT0=0;//PT0为0时为低优先级，为1时为高优先级
// }

/*
//定时器中断程序模板
void Timer0_Routine(void) interrupt 1
{
	static unsigned int T0Count;
	//使下一次定时器仍为1ms
	TH0=0xFC;
	TL0=0x18;

	//达到1s后执行程序
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
		
	}
}
*/