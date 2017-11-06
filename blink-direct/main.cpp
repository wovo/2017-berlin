// blink the on-board LED at PORTC, pin 13
   
#include "stm32f103x6.h"

void wait();

int main( void ){  
 
   // enable the PORTC peripheral clock
   RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
      
   // make the pin an output	  
   GPIOC->CRH &= ~( 0x0F << 20 ); // CRH if pin > 7
   GPIOC->CRH |=  ( 0x03 << 20 ); // 20 = 4 * ( 13 % 8 )
      
   for(;;){      
       GPIOC->BSRR = ( 0x01 << 13 ); // 1 << 13 for reset
       wait();
       GPIOC->BSRR = ( 0x01 << 29 ); // 1 << ( 13 + 16 ) for set
       wait();
   };
   
}
