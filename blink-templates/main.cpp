// #include "blue-pill.hpp"
#include "hwlib-stm32f103c8.hpp"

auto f = [&](){};

int main( void ){
    
   auto led = hwlib::target::pin_out( hwlib::target::pins::led );     ;

   hwlib::blink( led );
   
}
