#include <delay.h>
#include <mega16.h>

 int counterOverflow = 0;
 int counter = 0;
 int numbers[10] = {
	0b00111111 , 
	0b00000110 , 
	0b01011011 , 
	0b01001111 , 
	0b01100110 , 
	0b01101101 , 
	0b01111101 , 
	0b00000111 ,
	0b01111111 ,
	0b01101111
	};

interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
    ++counterOverflow;
 
       if(counterOverflow == 100 ){
          if(counter < 10){
           PORTD =  numbers[counter];
         }
	else{
           counter = 0;
           PORTD = numbers[counter];
         }
         counter++;
        }

           TCNT1H=0xFF;
           TCNT1L=0xF0;

}

void main(void)
{

DDRD=0b11111111;
PORTD=0b00000000;

//timerCounterControlRegister1 init
TCCR1A = 0x00;
TCCR1B = 0x01;
TCNT1H = 0xFF;
TCNT1L = 0xF0;

MCUCR = (0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR = (0<<ISC2);



TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (1<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

#asm("sei")

while (1)
      {}
}
