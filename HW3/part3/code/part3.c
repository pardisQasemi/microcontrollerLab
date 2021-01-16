#include <mega16.h>
#include <delay.h>
#include <alcd.h>
#include <stdio.h>

#define ICR1 256 * ICR1H + ICR1L;

int timerCounterForOverflow = 0;
char frequencyChars[100];
int begin = 0;
int end = 0;
int timeLenght = 0;
long freq;

interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
    ++timerCounterForOverflow;
    if(timerCounterForOverflow == 100){

        TCCR1A = 0;
        TCNT1=0;
        TIFR = (1<<ICF1); 
        //calculating begin
        TCCR1B = 0x41;
        while ((TIFR&(1<<ICF1)) == 0);
        begin = ICR1;
        TIFR = (1<<ICF1);
        //calculating end
        TCCR1B = 0x41;
        while ((TIFR&(1<<ICF1)) == 0);
        end = ICR1;
        TIFR = (1<<ICF1);

        TCCR1B = 0;

        if(begin < end)
        {   
            lcd_clear();
            timeLenght = end - begin;
            freq= 8000000UL/timeLenght;
            sprintf(frequencyChars,"Frequency calculated = %d", (int)freq);
            lcd_puts(frequencyChars);
        }
        else { 

            lcd_puts("calculate");  

        }
    }
    
    TCNT1H=0xFF;
    TCNT1L=0xF0;
}
void main(void)
{
    lcd_init(20);
    DDRA =0xFF;
    PORTA = 0x00;

DDRD=0b11111111;
PORTD=0b00000000;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 125.000 kHz
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer Period: 0.52429 s
// Timer1 Overflow Interrupt: On
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off

TCCR1A=0x00;
TCCR1B=0x01;
TCNT1H=0xFF;
TCNT1L=0xF0;


// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);


// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (1<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

#asm("sei")

while (1)
      {}
}
