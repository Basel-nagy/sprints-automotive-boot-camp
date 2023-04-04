#ifndef _EXTERNAL_INTERRUPT_H_
#define _EXTERNAL_INTERRUPT_H_
typedef enum EN_error_t {ok, not_ok} EN_error_t;
typedef enum EN_edge_t {rising_edge, falling_edge, any_chang, high_level} EN_edge_t;
typedef enum EN_external_interrupt {int0, int1, int2} EN_external_interrupt;
typedef struct ST_interrupt_t
{
	EN_external_interrupt interrupt;
	EN_edge_t edge;
} ST_interrupt_t;

/*description: this function set the external interrupt configuration
*Arguments: pointer to external interrupt config
*Return: ok if function fine, Not_ok if something wrong happens
*/
EN_error_t external_interrupt_init (ST_interrupt_t interrupt_config);

/*description: this function enable the external interrupt
*Arguments: external interrupt enum
*Return: ok if function fine, Not_ok if something wrong happens
*/
EN_error_t external_interrupt_enable (EN_external_interrupt interrupt);


/*description: this function set call back function
*Arguments: pointer to the caller function
*Return: ok if function fine, Not_ok if something wrong happens
*/
EN_error_t external_interrupt0_callbackfunc (void (ext_int0_ptr)(void));
EN_error_t external_interrupt1_callbackfunc (void (ext_int1_ptr)(void));
EN_error_t external_interrupt1_callbackfunc (void (ext_int1_ptr)(void));

#endif
