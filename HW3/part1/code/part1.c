#include <mega16.h>
#include <alcd.h>

void main(void)
{

    DDRC=0b00000000;
    PORTC=0b00000000;
    
    lcd_init(20);   
    
    while(1)
    {
        lcd_gotoxy(0,0);

        lcd_putsf("hello-world");
    }
}
