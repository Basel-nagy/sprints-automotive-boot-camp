#ifndef _TIMER_H_
#define _TIMER_H_
typedef enum EN_error_t {ok, not_ok} EN_error_t;
typedef enum EN_modes_t {normal, ctc, fast_pwm, phase_correct} EN_modes_t;
typedef struct ST_timer_t
{
	EN_modes_t mode;
	Uint16_t prescaller;
	
} ST_timer_t;

/*description: this function initializes the timer driver
*Arguments: pointer to timer_config
*Return: ok if function fine, Not_ok if something wrong happens
*/
EN_error_t timer_init (ST_timer_t timer_config);

/*description: this function start the timer with choose prescaller
*Arguments: take the pre_scaller
*Return: ok if function fine, Not_ok if something wrong happens
*/
EN_error_t timer_start (uint16_t prescaller);

/*description: this function stops the timer
*Arguments: void
*Return: void
*/
void timer_stop (void);
/*description: this function set the call back function
*Arguments: pointer to the callee function
*Return: ok if function fine, Not_ok if something wrong happens
*/
EN_error_t timer_ovf_callbackfunc (void (*timer_ovr_ptr) (void) );
EN_error_t timer_comp_callbackfunc (void (*timer_comp_ptr) (void) );

#endif