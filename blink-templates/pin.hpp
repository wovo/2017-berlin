#include "stm32f103x6.h"

GPIO_TypeDef * port_registers[] = {  GPIOA, GPIOB, GPIOC, GPIOD };

template< int port, int pin >
class gpio {
public:
   static void set( bool value ){
      port_registers[ port ]->BSRR = 
         0x01 << ( ( pin % 16 ) + ( value ? 0 : 16 ) );
   }
};