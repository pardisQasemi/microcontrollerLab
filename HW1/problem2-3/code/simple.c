#include <mega16.h>
#include <delay.h>
#define LED0 PORTB.0
#define LED1 PORTB.1
#define LED2 PORTB.2
#define LED3 PORTB.3
#define LED4 PORTB.4
#define LED5 PORTB.5
#define LED6 PORTB.6
#define LED7 PORTB.7
#define on 1
#define off 0

void main(void)
{
    DDRA = 0x00;   
    PINA = 0x00;  
    DDRB = 0xff;  
    PORTB = 0x00;
    #asm("sei")

    while (1) {  
            if(PINA.0==1)    
            {  
                LED0 = on;
                delay_ms(30);
                LED0 = off;
                LED1 = on;
                delay_ms(30);
                LED1 = off;
                LED2 = on;
                delay_ms(30);
                LED2 = off;
                LED3 = on;
                delay_ms(30);
                LED3 = off;
                LED4 = on;
                delay_ms(30);
                LED4 = off;
                LED5 = on;
                delay_ms(30);
                LED5 = off;
                LED6 = on;
                delay_ms(30);
                LED6 = off;
                LED7 = on;
                delay_ms(30);
                LED7 = off;
                LED6 = on;
                delay_ms(30);
                LED6 = off; 
                LED5 = on;
                delay_ms(30);
                LED5 = off;
                LED4 = on;
                delay_ms(30);
                LED4 = off;
                LED3 = on;
                delay_ms(30);
                LED3 = off;
                LED2 = on;
                delay_ms(30);
                LED2 = off;
                LED1 = on;
                delay_ms(30);
                LED1 = off;
                LED0 = on;
                delay_ms(30);
                LED0 = off;
            } else {
                PORTB = 00000000;
            }
    }
}