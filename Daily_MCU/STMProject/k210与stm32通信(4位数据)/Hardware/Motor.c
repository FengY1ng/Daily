#include "stm32f10x.h"                  // Device header
#include "PWN.h"
void Motor_Init(void)
{
	PWM_Init3();
}
// you
void Motor_SetSpeed2(int16_t Speed)
{
	
		PWM_SetCompare3(50-Speed/2);
		PWM_SetCompare1(50+Speed/2);

	
}
//zuo
void Motor_SetSpeed1(int16_t Speed)
{
	
		PWM_SetCompare2(50-Speed/2);
		PWM_SetCompare4(50+Speed/2);

}
