/*
 * bai_6.c
 *
 * Created: 30-Oct-20 9:22:34 AM
 * Author: QuynhNhi
 * Viet chuong trinh hien thi dong chu hello world len glcd
 */

#include <io.h>
#include <glcd.h>
#include <delay.h>
#include <font5x7.h>
#include <stdio.h>
#define LED_G PORTD.5
unsigned int gia_tri_adc;
unsigned char buffer[10];
unsigned int i = 0;


#define ADC_VREF_TYPE ((0<<REFS1) | (0<<REFS0) | (0<<ADLAR))

// Read the AD conversion result
unsigned int read_adc(unsigned char adc_input)
{
ADMUX=adc_input | ADC_VREF_TYPE;
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=(1<<ADSC);
// Wait for the AD conversion to complete
while ((ADCSRA & (1<<ADIF))==0);
ADCSRA|=(1<<ADIF);
return ADCW;
}

void main(void)
{
GLCDINIT_t glcd_init_data;
glcd_init_data.font = font5x7;
glcd_init_data.temp_coef = 90;   //so nay thay doi duoc
glcd_init_data.bias = 4;   //thay doi so
glcd_init_data.vlcd = 60;  //thay doi
glcd_init(&glcd_init_data);
PORTD.7 = 1;
ADMUX=ADC_VREF_TYPE;
ADCSRA=(1<<ADEN) | (0<<ADSC) | (0<<ADFR) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
SFIOR=(0<<ACME);
//DDRD = 0x20;
DDRD = 0xA0;
PORTD = 0x00;
PORTD.7 = 0;
while (1)
    {
    // Please write your application code here
        /*glcd_moveto(0,0);
        glcd_outtext("hello world");   */ 
        for(i = 0; i<4; i++){
            gia_tri_adc = read_adc(0);
            sprintf(buffer, "%d  ", gia_tri_adc);
            glcd_outtextxy(10,10,buffer);        
        } 
        /*gia_tri_adc = read_adc(0);
        sprintf(buffer, "%d  ", gia_tri_adc);
        glcd_outtextxy(10,10,buffer);  */
        //delay_ms(250);
        if (gia_tri_adc <= 700){
            PORTD.5 = 1;
            }
        else
            PORTD.5 = 0;
    }
}
