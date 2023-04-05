
/*
 * button.h
 *
 * Created: 4/5/2023 2:14:26 PM
 *  Author: basel
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
/************************************************************************/
/* including sections                                                   */
/************************************************************************/
#include "../../MCAL/DIO DRIVER/DIO.h"
/************************************************************************/
/* typedefs                                                             */
/************************************************************************/
typedef  enum EN_BUTTON_STATE_t {PUSHED,RELEASED}EN_BUTTON_STATE_t;
typedef struct BUTTON
{
	DIO_PORTS port;
	DIO_PINS pin;
}BUTTON;
/******************************************    APIs PROTOTYPES      *******************************************************************/
STD_return BUTTON_INIT (BUTTON*  button);
STD_return BUTTON_READ (DIO_PORTS port, DIO_PINS pin, EN_BUTTON_STATE_t* value);




#endif /* BUTTON_H_ */