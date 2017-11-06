#include "stm32f103x6.h"
#include "pin.hpp"

GPIO_TypeDef * port_registers[] = {  GPIOA, GPIOB, GPIOC, GPIOD };

pin::pin( int port, int num ): port( port ), num( num ){}
void pin::set( bool value ){
   port_registers[ port ]->BSRR = 
      0x01 << ( ( num % 16 ) + ( value ? 0 : 16 ) );
}    
