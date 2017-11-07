// blink the on-board LED at PORTC, pin 13
#include "stm32f103x6.h"
#include "pin.hpp"

void wait();

int main( void ){
    
 
   RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;    
   
   GPIOC->CRH &= ~( 0x0F << 20 ); // CRH if pin > 7
   GPIOC->CRH |=  ( 0x03 << 20 ); // 20 = 4 * ( 13 % 8 )   
    
   using led = gpio< 2, 13 >;

   for(;;){      
       led::set( true );
       wait();
       led::set( false );
       wait();
   };
   
}
