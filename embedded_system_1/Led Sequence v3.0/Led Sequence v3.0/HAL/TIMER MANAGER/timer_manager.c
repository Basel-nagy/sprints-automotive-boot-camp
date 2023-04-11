/*
 * timer_manager.c
 *
 * Created: 4/10/2023 2:49:42 AM
 *  Author: basel
 */ 
#include"timer_manager.h"
STD_return TIMER_MANAGER_CFG (ST_timerCFG_t * timer_cfg)
{
	
		STD_return ret_val=ok;
		switch(timer_cfg->mode)
		{
			case normal: TIMER_INIT(normal); if(timer_cfg->interrupt==ENABLE)
			{
				TIMER_OVF_INT_ENABLE();
			}
			else if(timer_cfg->interrupt==DISABLE)
			{
				TIMER_OVF_INT_DISABLE();
			}
			else
			{
				ret_val=not_ok;
			}
			 OVF_VALUE (timer_cfg->init_value);
			 TIMER_OVF_CALLBACK (timer_cfg->func_ptr);
			 break;
			case ctc:TIMER_INIT(ctc);
			if(timer_cfg->interrupt==ENABLE)
			{
				TIMER_COMP_INT_ENABLE();
			}
			else if(timer_cfg->interrupt==DISABLE)
			{
				TIMER_COMP_INT_DISABLE();
			}
			else
			{
				ret_val=not_ok;
			}
			 COMP_VALUE (timer_cfg->init_value);
			 TIMER_COMP_CALLBACK (timer_cfg->func_ptr);
			 break;
			case pwm:TIMER_INIT(pwm);
			case phase_correct:TIMER_INIT(phase_correct);
			default: ret_val=not_ok;break;
		}
		return ret_val;
	
}
void TIMER_MANAGER_STA (uint16_t prescaller)
{
	TIMER_START(prescaller);
}
void TIMER_MANAGER_STO (void)
{
	TIMER_STOP();
}