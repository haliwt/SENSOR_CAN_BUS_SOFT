/***********************************************************
*
*˫CAN���ߣ�
*
*
************************************************************/


#include "led.h"
#include "delay.h"
#include "sensor.h"
#include "sys.h"
#include "can.h" 
#include "can2.h"
#include "rs232.h"
#include "usart.h"
#include "at24cxx.h"
 
#define ExtendID_1   0xA000000a   //CAN 1 
#define ExtendID_2   0xB000000a   //CAN 2

 
 int main(void)
 {	 	
	u8 i=0,j=0;
	u8 value=0;
	u8 trig_canbuf[8]={0x50,1,1,1,0,0,0,0};  //������1 ,���������ź� 2017.11.25
	u8 trig_canbuf2[8]={0x50,2,2,2,0,0,0,0}; //������2, ���������ź�
	u8 trig_canbuf3[8]={0x50,3,3,3,0,0,0,0}; //������3,
	u8 notrig_canbuf[8]={0x0A};   //û�д����ģ����͵��ź�
	u8 mode=CAN_Mode_Normal;//CAN����ģʽ;CAN_Mode_Normal(0)����ͨģʽ��CAN_Mode_LoopBack(1)������ģʽ
     RS232_init();//����1��ʼ��
	delay_init();	    	 //��ʱ������ʼ��	  
  LED_Init();	
  I2C_INIT();		 //IIC��ʼ��
	SENSOR_Init();
 
  CAN1_Mode_Init(CAN_SJW_1tq,CAN_BS2_8tq,CAN_BS1_9tq,16,mode);//CAN��ʼ������ģʽ,������125Kbps     
  CAN2_Mode_Init(CAN_SJW_1tq,CAN_BS2_8tq,CAN_BS1_9tq,16,mode);//CAN��ʼ������ģʽ,������125Kbps    
	
 while(1)
 {
       
		AT24Cxx_WriteOneByte(0,0x5);	  //24c02д����
		value=AT24Cxx_ReadOneByte(0);
		trig_canbuf[7]=value;
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)==0)  //���������� 1
    {
		  delay_ms(10);
		  if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)==0)   //
			{
				Can1_Send_Msg(trig_canbuf,ExtendID_1,CAN_RTR_Data);//����8���ֽ� 
				delay_ms(10);
				Can2_Send_Msg(trig_canbuf,ExtendID_2,CAN_RTR_Data);//����8���ֽ
				delay_ms(10);
				LED1=1;		//  smd led ��˸
				LED0=1;
				delay_ms(100);
				LED1=0;
				LED0=0;
				delay_ms(100);
				LED1=1;
				 LED0=1;			
				delay_ms(100);
				LED1=0;
				LED0=0;	
				delay_ms(100);
				LED1=1;
				LED0=1;		
     				
				}
	 }
	/**************************����������2*******************************/
	 else if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)==0)
	 {
			delay_ms(10);
			if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)==0)
			{
			  Can1_Send_Msg(trig_canbuf2,ExtendID_1,CAN_RTR_Data);//����8���ֽ� 
		      delay_ms(10);
		      Can2_Send_Msg(trig_canbuf2,ExtendID_2,CAN_RTR_Data);//����8���ֽ
				    delay_ms(10);
					LED1=1;		//  smd led ��˸
					LED0=1;
					delay_ms(50);
					LED1=0;
					LED0=0;
					delay_ms(50);
					LED1=1;
					LED0=1;			
					delay_ms(50);
					LED1=0;
				    LED0=0;
				    delay_ms(50);
					LED1=1;
					LED0=1;
			}
		}
	 /**************************����������3***********************************************/
		else if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)==0)
		{
			   delay_ms(10);
			   if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)==0)
			   {
				 Can1_Send_Msg(trig_canbuf3,ExtendID_1,CAN_RTR_Data);//����8���ֽ� 
		         delay_ms(10);
		         Can2_Send_Msg(trig_canbuf3,ExtendID_2,CAN_RTR_Data);//����8���ֽ
				 delay_ms(10);
					LED1=1;		//  smd led ��˸
					LED0=1;
					delay_ms(50);
					LED1=0;
					LED0=0;
					delay_ms(50);
					LED1=1;
					LED0=1;			
					delay_ms(50);
					LED1=0;
				    LED0=0;
				 	delay_ms(50);
					LED1=1;
					LED0=1;	
			 }
		}
		
	  /*******************************û�д�����������************************************************/
		else 
		{
			   for(i=0;i<101;i++)
			        {
          			      delay_ms(10);
						  if(i==100)
							{
								notrig_canbuf[1]=0x01;
								Can1_Send_Msg(notrig_canbuf,ExtendID_1,CAN_RTR_Data);//����8���ֽ� 
								delay_ms(5);
								Can2_Send_Msg(notrig_canbuf,ExtendID_2,CAN_RTR_Data);//����8���ֽ
								delay_ms(5);
			                    notrig_canbuf[1]=0x02;
			                    Can1_Send_Msg(notrig_canbuf,ExtendID_1,CAN_RTR_Data);//����8���ֽ�
                 	             delay_ms(5);									
								 Can2_Send_Msg(notrig_canbuf,ExtendID_2,CAN_RTR_Data);//����8���ֽ
			           	         delay_ms(5);
								 notrig_canbuf[1]=0x03;
								 Can1_Send_Msg(notrig_canbuf,ExtendID_1,CAN_RTR_Data);//����8���ֽ� 
								 delay_ms(5);
								 Can2_Send_Msg(notrig_canbuf,ExtendID_2,CAN_RTR_Data);//����8���ֽ
								 delay_ms(5);
					
							  }
								for(j=0;j<200;j++)
								{
								  if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)==0)
								{
								 delay_ms(10);
								 if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)==0)
								{
									Can1_Send_Msg(trig_canbuf,ExtendID_1,CAN_RTR_Data);//����8���ֽ� 
									delay_ms(10);
									Can2_Send_Msg(trig_canbuf,ExtendID_2,CAN_RTR_Data);//����8���ֽ
									delay_ms(500);
									delay_ms(500);
									LED1=1;		//  smd led ��˸
									LED0=1;
									delay_ms(100);
									LED1=0;
									LED0=0;
									delay_ms(100);
									LED1=1;
									LED0=1;			
									delay_ms(100);
									LED1=0;
									LED0=0;	
								}
							}	
							
						 
						
						else if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)==0)
						{
								 delay_ms(5);
							   if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)==0)
										{
											delay_ms(10);
											Can1_Send_Msg(trig_canbuf2,ExtendID_1,CAN_RTR_Data);//����8���ֽ� 
											 delay_ms(10);
											 Can2_Send_Msg(trig_canbuf2,ExtendID_2,CAN_RTR_Data);//����8���ֽ
											 delay_ms(500);
									         delay_ms(500);
												LED1=1;		//  smd led ��˸
												LED0=1;
												delay_ms(100);
												LED1=0;
												LED0=0;
												delay_ms(100);
												LED1=1;
												LED0=1;			
												delay_ms(100);
												LED1=0;
											  LED0=0;
										}
							  
						     }
					       else if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)==0)
						     {
								  delay_ms(5);
							      if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)==0)
									 {
										delay_ms(10);
										 Can1_Send_Msg(trig_canbuf3,ExtendID_1,CAN_RTR_Data);//����8���ֽ� 
										 delay_ms(10);
										 Can2_Send_Msg(trig_canbuf3,ExtendID_2,CAN_RTR_Data);//����8���ֽ
										 delay_ms(500);
									   delay_ms(500);
											LED1=1;		//  smd led ��˸
											LED0=1;
											delay_ms(100);
											LED1=0;
											LED0=0;
											delay_ms(100);
											LED1=1;
											LED0=1;			
											delay_ms(100);
											LED1=0;
										  LED0=0;
									 }
							  }
					
                }  //end for(j=0;)
		     }
	    }
    
  } //end while(1)
}
		








