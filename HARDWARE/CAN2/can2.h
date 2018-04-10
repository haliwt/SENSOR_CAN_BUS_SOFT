#ifndef __CAN2_H
#define __CAN2_H	 
#include "sys.h"	    
 
//CAN接收RX0中断使能
#define CAN2_RX0_INT_ENABLE	0		//0,不使能;1,使能.								    
										 							 				    
u8 CAN2_Mode_Init(u8 tsjw,u8 tbs2,u8 tbs1,u16 brp,u8 mode);//CAN初始化
 
u8 Can2_Send_Msg(u8* msg2,uint32_t extid2,uint32_t rtr2_mode);						//发送数据

u8 Can2_Receive_Msg(u8 *buf2,u8 *extid2);							//接收数据
#endif

















