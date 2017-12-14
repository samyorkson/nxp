/*
 * user.c
 *
 *  Created on: 2017年12月13日
 *      Author: sam
 */


#include "user.h"


UART1_TComData max485_rx_buffer[64];
UART1_TComData testorder[8] = {0x01, 0x03, 0x00, 0x04, 0x00, 0x02, 0x85, 0xCA};
//UART1_TComData testorder2[8] = {0x01, 0x03, 0x00, 0x20, 0x00, 0x02, 0xC5, 0xC1};


void usermain(void)
{
	byte s;
	word snd;
	word len = 0;
	s = MAX485_Send(testorder, 8);
	for(int i = 0; i < 10000; i++) {;}
	UART0_SendChar(s);
	UART0_SendChar(0xAA);

	for(int i = 0; i < 300; i++) {
			for(int j = 0; j < 10000; j++);
		}

	if(MAX485_receiveflag) {
		MAX485_Receive(max485_rx_buffer, &len);
		for(int i = 0; i < 10000; i++) {;}
		UART0_SendBlock(max485_rx_buffer, len, &snd);
	}

	for(int i = 0; i < 3000; i++) {
		for(int j = 0; j < 10000; j++);
	}

}
