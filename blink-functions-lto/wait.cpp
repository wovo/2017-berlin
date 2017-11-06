void wait(){
   for( volatile int i = 0; i < 100'000; ++i ){}
}