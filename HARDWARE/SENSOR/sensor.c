#include "sensor.h"

void SENSOR_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;               //����һ���ṹ�������������ʼ��GPIO

    /* ����GPIOʱ�� */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    /*  ����GPIO��ģʽ��IO�� */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6;        //ѡ����Ҫ���õ�IO��
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;

    /* ��ʼ��GPIO PB10 */
    GPIO_Init(GPIOA,&GPIO_InitStructure); 
	  GPIO_SetBits(GPIOA,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6);
 	 
	 
	}
