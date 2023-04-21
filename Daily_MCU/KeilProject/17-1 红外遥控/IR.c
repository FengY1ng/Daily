#include <REGX52.H>
#include "Timer0.h"
#include "Int0.h"

unsigned int IR_Time;//计时
unsigned char IR_State;

unsigned char IR_Data[4];
unsigned char IR_pData;

unsigned char IR_DataFlag;
unsigned char IR_RepeatFlag;
unsigned char IR_Address;
unsigned char IR_Command;

/**
 * @brief  红外遥控
 * @param  无
 * @retval 无
 */
void IR_Init(void)
{
    Timer0_Init();
    Int0_Init();
}

/**
 * @brief  红外遥控获取接收到的数据帧标志位
 * @param  无
 * @retval 是否接收到数据帧，1为接收到，0为未接收到
*/
unsigned char IR_GetDataFlag(void)
{
    if(IR_DataFlag)
    {
        IR_DataFlag=0;
        return 1;
    }
    return 0;
}

/**
 * @brief  红外遥控获取接收到的重复帧标志位
 * @param  无
 * @retval 是否接收到重复帧，1为接收到，0为未接收到
*/
unsigned char IR_GetRepeatFlag(void)
{
    if(IR_RepeatFlag)
    {
        IR_RepeatFlag=0;
        return 1;
    }
    return 0;
}

/**
 * @brief  红外遥控获取接收到的地址数据
 * @param  无
 * @retval 地址数据
*/
unsigned char IR_GetAddress(void)
{
    return IR_Address;
}

/**
 * @brief  红外遥控获取接收到的命令数据
 * @param  无
 * @retval 命令数据
*/
unsigned char IR_GetCommand(void)
{
    return IR_Command;
}

//红外遥控中断服务函数，下降沿触发执行
void Int0_Routine(void) interrupt 0
{
	if(IR_State==0)
    {
        Timer0_SetCounter(0);
        Timer0_Run(1);
        IR_State=1;
    }
    else if(IR_State==1)
    {
        IR_Time=Timer0_GetCounter();    //获取上一次中断到此次中断的时间
        Timer0_SetCounter(0);           //清零计数器
        //如果计时为13.5ms，说明是起始信号（判定值在12MHz晶振下为13500，在11.0592MHz晶振下为12442）
        if(IR_Time>12442-500 && IR_Time<12442+500)
        {
            IR_State=2;                 //置状态为2，进入数据接收状态。
        }
        //如果计时为11.25ms，说明是重复信号（判定值在12MHz晶振下为11250，在11.0592MHz晶振下为10368）
        else if(IR_Time>10368-500 && IR_Time<10368+500)
        {
            IR_RepeatFlag=1;            //置重复帧标志位为1
            Timer0_Run(0);              //定时器停止
            IR_State=0;                 //置状态为0，进入等待状态。
        }
        else                            //接收出错
        {
            IR_State=1;                 //置状态为1，进入等待状态。
        }
    }
    else if(IR_State==2)                //状态2，接收数据
    {
        IR_Time=Timer0_GetCounter();    //获取上一次中断到此次中断的时间
        Timer0_SetCounter(0);           //定时计数器清零
        //如果计时为1120us，说明是0（判定值在12MHz晶振下为1120，在11.0592MHz晶振下为1032）
        if(IR_Time>=1032-500 && IR_Time<1032+500)
        {
            IR_Data[IR_pData/8]&=~(0x01<<(IR_pData%8));//数据位对应的字节清零
            IR_pData++;                 //数据位指针自增
        }
        //如果计时为2250us，说明是1（判定值在12MHz晶振下为2250，在11.0592MHz晶振下为2074）
        else if(IR_Time>=2074-500 && IR_Time<2074+500)
        {
            IR_Data[IR_pData/8]|=(0x01<<(IR_pData%8));//数据位对应位置1
            IR_pData++;                 //数据位指针自增
        }
        else                            //接收出错
        {
            IR_pData=0;                 //数据位指针清零
            IR_State=1;                 //置状态为1，进入等待状态。
        }
        if(IR_pData>=32)
        {
            IR_pData=0;
            if((IR_Data[0]==~IR_Data[1]) && (IR_Data[2]==~IR_Data[3]))
            {
                IR_Address=IR_Data[0];
                IR_Command=IR_Data[2];
                IR_DataFlag=1;
            }
            Timer0_Run(0);
            IR_State=0;
        }
    }
}
