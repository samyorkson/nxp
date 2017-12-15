/*******************************************************************************
 *  File name: max485.c
 *  Author: sam
 *  Date: 2017-12-13
 *  Description: Providing the transceiver function of the MAX485 module 
                 through the UART1 and a GPIO.
 *  Note: This file is only used on FRDM-KL25Z.
*******************************************************************************/

#include "max485.h"

/*  Data processing flag */
byte MAX485_sendcomplete = 0;
byte MAX485_receiveflag = 0;

/*******************************************************************************
 *  @func: MAX485_Send
 *  @brief: Calling the UART1 and GPIO modules to control the MAX485 module to 
            send data.
 *  @param: *Ptr ---- A pointer to the data that needs to be sent.
            Size ---- Data size.
 *  @return: s ---- Sending results.
                    Success: 0
                    fail: 1
 *  @note: Please set MAX485_sendcomplete to 1 
           in the corresponding interruption or event of UART1.
*******************************************************************************/
byte MAX485_Send(UART1_TComData *Ptr, word Size)
{
    byte s;
    word sent_len = 0;
    MAX485_sendcomplete = 0;
    MAX485_DIR_SetVal(NULL);

    if(UART1_GetCharsInTxBuf) {
		while(UART1_ClearTxBuf() != ERR_OK) {;}
	}

	s = UART1_SendBlock(Ptr, Size, &sent_len);

	if(s == ERR_OK) {
        s = 0;
        while(!MAX485_sendcomplete) {;}
    }
    else {
        s = 1;
    }

    MAX485_DIR_ClrVal(NULL);

	return s;
}

/*******************************************************************************
 *  @func: MAX485_Receive
 *  @brief: Calling the UART1 and GPIO modules to control the MAX485 module to 
            receive data.
 *  @param: *Ptr ---- Pointer to a buffer for receiving data.
            *Size ---- Pointer to number of the received data.
 *  @return: s ---- Receiving result.
                    Success: 0
                    fail: 1
 *  @note: Please set MAX485_receiveflag to 1 
           in the corresponding interruption or event of UART1.
*******************************************************************************/
byte MAX485_Receive(UART1_TComData *Ptr, word *Size)
{
    byte s;
    byte buffer_size = 64;      //Set to the receive buffer size of UART1.
    MAX485_DIR_ClrVal(NULL);

    s = UART1_RecvBlock(Ptr, buffer_size, Size);

    if(s == ERR_OK) {
        s = 0;
    }
    else {
        s = 1;        
    }

    MAX485_receiveflag = 0;

    return s;
}
/*  max485.c end. */
