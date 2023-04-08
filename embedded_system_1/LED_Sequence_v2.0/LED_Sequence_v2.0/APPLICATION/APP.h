/*
 * APP.h
 *
 * Created: 4/7/2023 4:29:45 PM
 *  Author: basel
 */ 


#ifndef APP_H_
#define APP_H_
/************************************************************************/
/* including sections                                                   */
/************************************************************************/
#include "../HAL/LED/LED.h"
#include "../HAL/EXTERNAL_INTERRUPT_MANAGER/EXTERNAL_INT_MANAGER.h"
/*macros*/
#define led1 pin0
#define led2 pin1
#define led3 pin2
#define led4 pin3
#define state_1 1
#define state_2 2
#define state_3 3
#define state_4 4
#define state_5 5
#define state_6 6
#define state_7 7
#define state_8 8
/************************************************************************/
/* APIs prototypes                                                      */
/************************************************************************/
STD_return APP_INIT(void);
void APP_START(void);
void interrupt_func(void);



#endif /* APP_H_ */