/*
 * bai_3.c
 *
 * Created: 09-Oct-20 9:11:40 AM
 * Author: QuynhNhi 
 * Viet chuong trinh bam cong tac 1 lan 1 thi den sang, lan 2 thi den tat. Lan 3 thi den sang, lan 4 thi den tat...  
 * Bam cong tac 1 den sang, 2 den tat, 3 nhap nhay theo chu ki 1s  
 * b3 bien dem dang char, chu ki 1phut
 */

#include <io.h>
#include <delay.h>
#define led     PORTE.5
#define CT1     PIND.3 //pind la thanh ghi de doc du lieu vao
#define CT2     PIND.5 //ct_2 = pd5
#define CT3     PIND.2 //ct_3 = pd2
#define sang    0
#define toi     1
unsigned char x = 0;
int dem;
interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{
// Reinitialize Timer 0 value
TCNT0=0x06;
if (x == 1)
{
    dem++; 
    if (dem == 1000)
    {
        led = sang;
    } 
    if (dem == 2000)
    {
        led = toi; 
        dem = 0;
    }             
    
}
// Place your code here

}
void main(void)
{
DDRD =  0x00;
DDRE =  0x20;
PORTE = 0x20;
PORTD = 0xFF; //pull up ca PORT D len nguon. 
//thong thuong voi loi vao la nut bam, nguoi ta se ket noi de khi bam, bus se dc noi xuong GND = 0 (dien ap 0v) => logic = 0 di vao trong chip
ASSR=0<<AS0;
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (1<<CS01) | (1<<CS00);
TCNT0=0x06;
OCR0=0x00;
ASSR=0<<AS0;
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (1<<CS01) | (1<<CS00);
TCNT0=0x06;
OCR0=0x00;
#asm("sei")
while (1)
    {
    // Please write your application code here
    if(CT1 == 0)
    {         
       delay_ms(250);   //chong rung ban phim
       // led = ~led;    
       led = sang;
       x = 0;
    }
    if(CT2 == 0)
    {         
        delay_ms(250);
        led = toi;  
        x = 0;
    } 
    if(CT3 == 0 )
    {
        delay_ms(250);
        x = 1;
    }
    }
}