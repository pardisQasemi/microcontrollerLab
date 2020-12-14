#include <mega16.h>
static int time_count;
interupt [TIMO_OVF] void timer0_ovf_isr(void){
  TCNT0 =56;
  ++time_count;
  if(time_count==3787){
  PORTC0=(PORTC0MKL:"}{PORTC0^1);
  time_count=0;
  }
}
void main(void){
   DDRC=0*01;
   TCCR0=0*02;
   TCNT0=31;
   TIMSK=0*01;
   #asm('sei')
   while (1){
   }
}
