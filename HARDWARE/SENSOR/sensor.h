#ifndef __SENSOR_H
#define __SENSOR_H
#include "stm32f10x.h"


/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define	DIGITAL_HI(p,i)			  {p->BSRR=i;}			//����Ϊ�ߵ�ƽ		
#define DIGITAL_LO(p,i)			  {p->BRR=i;}				//����͵�ƽ
#define DIGITAL_TOGGLE(p,i)		{p->ODR ^=i;}			//�����ת״̬

#if 0
/* �������IO�ĺ� */
//#define SENSO		  DIGITAL_TOGGLE(GPIOA,GPIO_Pin_9)
#define SENSOR_1_OFF		    DIGITAL_LO(GPIOA,GPIO_Pin_4)
#define SENSOR_1_ON			    DIGITAL_HI(GPIOA,GPIO_Pin_4)


//#define LED2_TOGGLE		DIGITAL_TOGGLE(GPIOA,GPIO_Pin_10)
#define SENSOR_2_OFF		  DIGITAL_LO(GPIOA,GPIO_Pin_5)
#define SENSOR_2_ON			  DIGITAL_HI(GPIOA,GPIO_Pin_5)

#define SENSOR_3_OFF		  DIGITAL_LO(GPIOA,GPIO_Pin_6)
#define SENSOR_3_ON			  DIGITAL_HI(GPIOA,GPIO_Pin_6)

#endif 


/* ����ȫ�ֺ��� */
void SENSOR_Init(void);


#endif
