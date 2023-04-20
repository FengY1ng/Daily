#include <REGX52.H>

/**
 * @brief  Initialize the interrupt 0
 * @param  None
 * @retval None
*/
void Int0_Init(void)
{
	IT0=0;
    IE0=0;
    EX0=1;
    EA=1;
    PX0=1;
}

/*!
void Int0_Routine(void) interrupt 0
{
	
}
*/