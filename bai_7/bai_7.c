/*
 * bai_7.c
 *
 * Created: 06-Nov-20 9:12:54 AM
 * Author: QuynhNhi  
 bam bt1 servo quay goc 90, servo 2 bt quay 135.
 */

#include <io.h>
#include <glcd.h>
#include <delay.h>
#include <font5x7>
#include <stdio.h>
#define servo PORTC.7
#define BT1 PINB.2
#define BT2 PINB.3
int dem;
char vitri;
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{

TCNT0=0xB0; //tao ra don vi 0.01 ms
dem++    ;
if (dem == 2000) dem = 0;
if (dem < vitri) servo = 1;
else servo = 0;

}



void main(void)
{
GLCDINIT_t glcd_init_data;
glcd_init_data.font = font5x7;
glcd_init_data.temp_coef = 90;   //so nay thay doi duoc
glcd_init_data.bias = 4;   //thay doi so
glcd_init_data.vlcd = 60;  //thay doi
glcd_init(&glcd_init_data);
DDRC = 0x80;
DDRB = 0x00;
PORTB = 0x0C;
ASSR=0<<AS0;
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (1<<CS00);
TCNT0=0xB0;
OCR0=0x00;
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);
ETIMSK=(0<<TICIE3) | (0<<OCIE3A) | (0<<OCIE3B) | (0<<TOIE3) | (0<<OCIE3C) | (0<<OCIE1C);
#asm("sei")

while (1)
    {     
    glcd_goto(0,0);
    if (BT1 == 0){ 
        delay_ms(250);
        vitri++; // vitri tang 1.8
        if (vitri == 200){
            vitri = 150;
            
        }
    }                            
    if (BT2 == 0){
        delay_ms(250);
        //vitri = 175; //servo quay goc 135    
        vitri--;
        if (vitri == 100){
            vitri = 150;
        }
    }

    }
}