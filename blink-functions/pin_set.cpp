#include "stm32f103x6.h"

GPIO_TypeDef * port_registers[] = {  GPIOA, GPIOB, GPIOC, GPIOD };

// pin == 32 * port + pin
void pin_set( int pin, bool value ){
   port_registers[ pin / 32 ]->BSRR = 
      0x01 << ( ( pin % 16 ) + ( value ? 0 : 16 ) );
}