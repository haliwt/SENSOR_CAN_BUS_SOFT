#include "sensor.h"

void SENSOR_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;               //声明一个结构体变量，用来初始化GPIO

    /* 开启GPIO时钟 */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    /*  配置GPIO的模式和IO口 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6;        //选择你要设置的IO口
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;

    /* 初始化GPIO PB10 */
    GPIO_Init(GPIOA,&GPIO_InitStructure); 
	  GPIO_SetBits(GPIOA,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6);
 	 
	 
	}
