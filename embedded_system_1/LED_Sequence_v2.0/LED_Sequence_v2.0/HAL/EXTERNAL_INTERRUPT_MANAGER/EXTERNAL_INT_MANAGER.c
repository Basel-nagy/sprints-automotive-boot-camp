/*
 * EXTERNAL_INT_MANAGER.c
 *
 * Created: 4/7/2023 9:27:15 PM
 *  Author: basel
 */ 
#include"EXTERNAL_INT_MANAGER.h"
STD_return EXT_INT_HANDLER(ST_EXT_INT_HANDLER_t* handler)
{  STD_return ret_val=ok;
	  if(handler==NULL)
	  {
		  ret_val = not_ok;
	  }
	  else
	  {
		  		 EDGE_SELECET(handler->edge_select,handler->ext_int);
				  switch(handler->ext_int)
				  {
				  case int0:SETCALLBACK_FUN_INT0(handler->function_ptr);EXT_INTERRUPT_ENABLE (handler->ext_int);break;
				  case int1:SETCALLBACK_FUN_INT1(handler->function_ptr);EXT_INTERRUPT_ENABLE ( handler->ext_int);break;
				  case int2:SETCALLBACK_FUN_INT2(handler->function_ptr);EXT_INTERRUPT_ENABLE ( handler->ext_int);break;
				  default:ret_val=not_ok;break;
				  }			   
	  }
		 return ret_val;
		
		
	
}