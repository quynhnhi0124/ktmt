/*
 * bai_5.c
 *
 * Created: 23-Oct-20 9:23:56 AM
 * Author: QuynhNhi
 */

#include <io.h>
#include <alcd.h>
#include <delay.h>
#include <stdlib.h>
#define CT1 PIND.3
#define CT2 PIND.5
#define CT3 PIND.2

char first = 0;
char second = 0;
char dem = 0;
char* str;

void main(void)
{
DDRD = 0x00;
PORTD = 0xFF;
lcd_init(16);
lcd_gotoxy(0,0);
while (1)
    {
    // Please write your application code here
    if(CT1 == 0){
        delay_ms(250);
        if(first == 0){
            first = 1;
        }
        else if(second == 0){
            second = 1;
        }
    
    }
    if(CT2 == 0){
        delay_ms(250);
        if(first == 0){
            first = 2;
        }
        else if(second == 0){
            second = 2;
        }
    }
    if(first == 1 && second == 2){
        dem++;
        first = 0;
        second = 0;
        lcd_gotoxy(0,0);
        itoa(dem,str);
        lcd_puts(str);
    }else if(first == 2 && second == 1){ 
        if(dem > 0){
            dem--;
        }  
        first = 0;
        second = 0;
        lcd_gotoxy(0,0);
        itoa(dem,str);
        lcd_puts(str);
    }
    if(first == second){
        second = 0;
    }
    /*if(CT3 == 0){
        delay_ms(250);
        lcd_gotoxy(0,0);
        itoa(dem,str);
        lcd_puts(str);
    }*/
    }                  
    
}
