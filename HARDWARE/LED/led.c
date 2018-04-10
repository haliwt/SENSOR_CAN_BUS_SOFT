#include "led.h"

//初始化PB5和PE5为输出口.并使能这两个口的时钟		    
//LED IO初始化
void LED_Init(void)
{
 
  GPIO_InitTypeDef GPIO_InitStructure;               //声明一个结构体变量，用来初始化GPIO

    /* 开启GPIO时钟 */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    /*  配置GPIO的模式和IO口 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;        //选择你要设置的IO口
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //设置传输速率
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //设置推挽输出模式

    /* 初始化GPIO */
    GPIO_Init(GPIOB,&GPIO_InitStructure);   
 	 
	  //将LED的IO口全部赋值为1，即熄灭LED灯
	  GPIO_ResetBits(GPIOB,GPIO_Pin_0);
	  GPIO_ResetBits(GPIOB,GPIO_Pin_1);
}
 
