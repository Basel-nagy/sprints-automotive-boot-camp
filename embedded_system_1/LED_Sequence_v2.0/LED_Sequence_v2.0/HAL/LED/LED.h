/*
 * LED.h
 *
 * Created: 4/5/2023 1:59:47 PM
 *  Author: basel
 */ 


#ifndef LED_H_
#define LED_H_
/************************************************************************/
/* including sections                                                   */
/************************************************************************/
#include "../../MCAL/DIO DRIVER/DIO.h"
/************************************************************************/
/* typedefs                                                             */
/************************************************************************/
typedef struct LED
{
	DIO_PORTS port;
	DIO_PINS pin;
}LED;
/******************************************    APIs PROTOTYPES      *******************************************************************/
STD_return LED_INIT (LED* led);
STD_return LED_ON (DIO_PORTS, DIO_PINS);
STD_return LED_OFF (DIO_PORTS,DIO_PINS);
#endif /* LED_H_ */