#ifndef __CAN2_H
#define __CAN2_H	 
#include "sys.h"	    
 
//CAN����RX0�ж�ʹ��
#define CAN2_RX0_INT_ENABLE	0		//0,��ʹ��;1,ʹ��.								    
										 							 				    
u8 CAN2_Mode_Init(u8 tsjw,u8 tbs2,u8 tbs1,u16 brp,u8 mode);//CAN��ʼ��
 
u8 Can2_Send_Msg(u8* msg2,uint32_t extid2,uint32_t rtr2_mode);						//��������

u8 Can2_Receive_Msg(u8 *buf2,u8 *extid2);							//��������
#endif

















