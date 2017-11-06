#include "stm32f103x6.h"

void wait();

#include "pin.hpp"

int main( void ){
    
   // on-board LED at PORTC, pin 13

   //RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;    
   
   //GPIOC->CRH &= ~( 0x0F << 20 ); // CRH if pin > 7
   //GPIOC->CRH |=  ( 0x03 << 20 ); // 20 = 4 * ( 13 % 8 )   
    
   auto led = pin( 2, 13 ); 

   for(;;){      
       led.set( true );
       wait();
       led.set( false );
       wait();
   };
   
}
