#include "led.h"

//��ʼ��PB5��PE5Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
void LED_Init(void)
{
 
  GPIO_InitTypeDef GPIO_InitStructure;               //����һ���ṹ�������������ʼ��GPIO

    /* ����GPIOʱ�� */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    /*  ����GPIO��ģʽ��IO�� */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;        //ѡ����Ҫ���õ�IO��
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //���ô�������
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //�����������ģʽ

    /* ��ʼ��GPIO */
    GPIO_Init(GPIOB,&GPIO_InitStructure);   
 	 
	  //��LED��IO��ȫ����ֵΪ1����Ϩ��LED��
	  GPIO_ResetBits(GPIOB,GPIO_Pin_0);
	  GPIO_ResetBits(GPIOB,GPIO_Pin_1);
}
 
