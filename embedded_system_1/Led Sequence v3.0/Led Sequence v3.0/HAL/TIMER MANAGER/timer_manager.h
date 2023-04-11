/*
 * timer_manager.h
 *
 * Created: 4/10/2023 2:49:29 AM
 *  Author: basel
 */ 


#ifndef TIMER_MANAGER_H_
#define TIMER_MANAGER_H_
#include "../../MCAL/TIMER/TIMER.h"
/*typedefs*/
typedef  void (*FUNC_ptr) (void);
typedef enum EN_timer_interrupt {ENABLE, DISABLE} EN_timer_interrupt;
typedef struct ST_timerCFG_t
{
	EN_timermode_t mode;
	EN_timer_interrupt interrupt;
	FUNC_ptr func_ptr;
	uint8_t init_value;
} ST_timerCFG_t;
/******************************************    APIs PROTOTYPES      *******************************************************************/
STD_return TIMER_MANAGER_CFG (ST_timerCFG_t * timer_cfg);
void TIMER_MANAGER_STA (uint16_t prescaller);
void TIMER_MANAGER_STO (void);






#endif /* TIMER_MANAGER_H_ */