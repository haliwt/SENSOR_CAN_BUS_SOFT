#ifndef __SENSOR_H
#define __SENSOR_H
#include "stm32f10x.h"


/* 直接操作寄存器的方法控制IO */
#define	DIGITAL_HI(p,i)			  {p->BSRR=i;}			//设置为高电平		
#define DIGITAL_LO(p,i)			  {p->BRR=i;}				//输出低电平
#define DIGITAL_TOGGLE(p,i)		{p->ODR ^=i;}			//输出反转状态

#if 0
/* 定义控制IO的宏 */
//#define SENSO		  DIGITAL_TOGGLE(GPIOA,GPIO_Pin_9)
#define SENSOR_1_OFF		    DIGITAL_LO(GPIOA,GPIO_Pin_4)
#define SENSOR_1_ON			    DIGITAL_HI(GPIOA,GPIO_Pin_4)


//#define LED2_TOGGLE		DIGITAL_TOGGLE(GPIOA,GPIO_Pin_10)
#define SENSOR_2_OFF		  DIGITAL_LO(GPIOA,GPIO_Pin_5)
#define SENSOR_2_ON			  DIGITAL_HI(GPIOA,GPIO_Pin_5)

#define SENSOR_3_OFF		  DIGITAL_LO(GPIOA,GPIO_Pin_6)
#define SENSOR_3_ON			  DIGITAL_HI(GPIOA,GPIO_Pin_6)

#endif 


/* 声明全局函数 */
void SENSOR_Init(void);


#endif
