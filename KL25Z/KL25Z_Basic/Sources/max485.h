/*******************************************************************************
 *  File name: max485.h
 *  Copyright: MyCompany
 *  Author: sam
 *  Date: 2017-12-13
 *  Description: Providing the transceiver function of the MAX485 module 
                 through the UART1 and a GPIO.
 *  Note: This file is only used on FRDM-KL25Z.
*******************************************************************************/

#ifndef SOURCES_MAX485_H_
#define SOURCES_MAX485_H_


/*  Including UART modules interface   */
#include "UART1.h"
/*  Including Direction pin modules interface   */
#include "MAX485_DIR.h"


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
extern byte MAX485_Send(UART1_TComData *Ptr, word Size);

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
extern byte MAX485_Receive(UART1_TComData *Ptr, word *Size);


/*  Data processing flag */
extern byte MAX485_receiveflag;
extern byte MAX485_sendcomplete;

#endif /* SOURCES_MAX485_H_ */
