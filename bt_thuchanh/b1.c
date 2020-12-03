/*
 * b1.c
 *
 * Created: 27-Nov-20 9:20:53 AM
 * Author: QuynhNhi
 */

#include <io.h>
#include <delay.h>
#include <alcd.h>
#define bt1 PINB.2
#define bt2 PINB.3
#define bt3 PINB.0

void main(void)
{
DDRB = 0x04;
PORTB = 0xff; //pullup tat ca thay vi 1
DDRD.7 = 1; //data direction = output
delay_ms(500);
lcd_init(16);
lcd_gotoxy(0,0);
lcd_clear();
//lcd_putsf("hello_world");

int p;  //vtri
int index = 0;
char s[11] = "hello_world";

while (1)
    {
    if(bt1 == 0)
    {
        delay_ms(250);
        for(index=0;index<11; index++)
        {
            for(p=0; p<16-index;p++)
            {
               lcd_gotoxy(p-1,0);
               lcd_puts(" ");
               lcd_gotoxy(p,0);
               lcd_puts(s[10-index]);  
            }   
        }        
    }
    if(bt2 == 0)
    {
        delay_ms(250);                 
        for(index=0;index<11;index++)
        {
            for(p=0;p<16-index;p++)
            {
                lcd_gotoxy(16-p.0);
                lcd_puts(" ");
                lcd_puts(s[]);
            }
        }
    }
    if(bt3 == 0)
    {    
        delay_ms(250);
        lcd_clear();
    }
    }
}
