/*
 * EXTERNAL_INT_MANAGER.h
 *
 * Created: 4/7/2023 9:27:37 PM
 *  Author: basel
 */ 


#ifndef EXTERNAL_INT_MANAGER_H_
#define EXTERNAL_INT_MANAGER_H_
/************************************************************************/
/* INCLUDING SECTIONS                                                   */
/************************************************************************/
#include"../../MCAL/EXTERNAL INTERRUPT/EXTERNAL_INTERRUPT.h"
/*typedefs*/
typedef void (*func_ptr)(void);
typedef struct ST_EXT_INT_HANDLER_t
{
EN_INT_NUM_t ext_int;
EN_EDGE_t edge_select;
func_ptr function_ptr;
}ST_EXT_INT_HANDLER_t;
 
/*function prototype*/ 
STD_return EXT_INT_HANDLER(ST_EXT_INT_HANDLER_t* handler);

#endif /* EXTERNAL_INT_MANAGER_H_ */