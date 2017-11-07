#include <stdlib.h>
#include <iostream>
#include "hwlib-stm32f103c8.hpp"

struct location { int x, y; };

void print_location( FILE * f, location v ){
   fprintf( f, "(%d,%d)", v.x, v.y );
}

std::ostream & operator<<( std::ostream & out, const location & v  ){
   return out << '(' << v.x << ',' << v.y << ')';
}

template< typename OUT >
auto operator<<( OUT & out, const location & v  ) -> decltype( out << 'x' ) & {
   return out << '(' << v.x << ',' << v.y << ')';
}

int main( void ){
   location loc{ 1, 2 };
   
   print_location( cout, loc );
   std::cout << loc;
   hwlib::cout << loc << loc;
}
