#ifndef _DIO_H_
#define _DIO_H_
Typedef enum EN_direction_t {input, output} EN_direction_t;
Typedef enum EN_vlevel_t {low, high} EN_vlevel_t;
typedef enum EN_ports_t {porta=0,portb,portc, portd} EN_ports_t;
typedef enum EN_pins_t {pin0=0, pin1 ,pin2 ,pin3 ,pin4 ,pin5 ,pin6 ,pin7} EN_pins_t;
typedef enum EN_error_t {ok, not_ok} EN_error_t;


/*description: this function initializes the dio driver
*Arguments: port, pin number, direction of the pin
*Return: ok if function fine, Not_ok if something wrong happens
*/
EN_error_t DIO_INIT (EN_ports_t port, EN_pins_t, EN_direction_t direction );

/*description: this function write high or low on specific pin
*arguments: port ,pin number, output level of the pin
*return: ok if function fine, Not_ok if something wrong happens
*/
EN_error_t DIO_WRITE (EN_ports_t port, EN_pins_t, EN_vlevel_t output);

/*description: this function read input on a specific pin
*Arguments: port, pin number
*Return: ok if function fine, Not_ok if something wrong happens
*/
EN_error_t DIO_READ (EN_ports_t port, EN_pins_t,uint8_t* state);

#endif