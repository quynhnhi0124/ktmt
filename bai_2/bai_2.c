/*
 * bai_2.c
 *
 * Created: 02-Oct-20 10:01:38 AM
 * Author: QuynhNhi
 */    
 
//viet chuong trinh LED sang-toi theo chu ki 1 giay blinking led
//viet ct sang 1 toi 1 sang 2 toi 2..
/* bt viet ctrinh bam nut CT! den sang tha nuts CT! den tat  
    ct_1 = PD3 => input => DDR = 0   
    bt viet ctrinh bam ct1 den sang bam ct2 den nhap nhay
*/

#include <io.h>
#include <delay.h> //thu vien de su dung ham lam tre (delay)

void main(void)
{
DDRE = 0x20;	// port e bit 5 la loi ra => thanh ghi tac dong = 1
DDRD = 0x00; //ca PORT D deu la input => D3 cung la input
PORTD = 0x28;    //pull up cho gtri = 1 tranh kha nang random  0b 0010 1000
while (1)
    {     
    
        /* PORTE = 0x00;    //den sang
        delay_ms(1000);  //delay lam cho CPU khong lam viec => co truong hop khi quay tro lai lam viec CPU lam hong dung nua
        PORTE = 0x20;    
        delay_ms(1000);
        PORTE = 0x00;    //den sang
        delay_ms(2000);  //delay lam cho CPU khong lam viec => co truong hop khi quay tro lai lam viec CPU lam hong dung nua
        PORTE = 0x20;    
        delay_ms(2000);
        while(1){
            PORTE = 0x20;
        }  */
        if(PIND.3 == 0)      //day la phep so sanh
        {
            PORTE.5 = 0x00;     //day la phep gan   
           // delay_ms(3000); bam ct1 den sang 3s
            
        }                
        else
        {
            PORTE = 0x20;
        }
        if (PIND.5 == 0)
        {
            PORTE = 0x00;
            delay_ms(50);
            PORTE = 0x20;
        }
    }
}
