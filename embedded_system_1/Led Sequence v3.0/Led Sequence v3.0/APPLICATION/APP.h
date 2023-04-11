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
#include "../HAL/TIMER MANAGER/timer_manager.h"
/*macros*/
#define led1 pin0
#define led2 pin1
#define led3 pin2
#define led4 pin3
#define ms_100 1
#define ms_200 2
#define ms_300 3
#define ms_500 5
#define ms_800 8
#define ms_900 9
#define ms_1000 10
/*typedefs*/
typedef enum EN_blink_state_t {BLINK_1,BLINK_2,BLINK_3,BLINK_4,BLINK_5}EN_blink_state_t;
typedef enum EN_states_t{state_1=1,state_2,state_3,state_4,state_5,state_6,state_7,state_8}EN_states_t;	
/************************************************************************/
/* APIs prototypes                                                      */
/************************************************************************/
STD_return APP_INIT(void);
void APP_START(void);
void INT0_func(void);
void INT1_func(void);
void timer_comp(void);



#endif /* APP_H_ */