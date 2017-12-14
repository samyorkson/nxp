/*
 * user.h
 *
 *  Created on: 2017年12月13日
 *      Author: sam
 */

#ifndef SOURCES_USER_H_
#define SOURCES_USER_H_


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "MAX485_DIR.h"
#include "UART0.h"
#include "ASerialLdd1.h"
#include "UART1.h"
#include "ASerialLdd2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/*	Including user modules	*/
#include "max485.h"


extern void usermain(void);


#endif /* SOURCES_USER_H_ */
