/*
 * bai_4.c
 *
 * Created: 16-Oct-20 9:20:51 AM
 * Author: QuynhNhi
 */

#include <io.h>
#include <alcd.h>
#include <delay.h>
#define ct1 PIND.3
#define ct2 PIND.5
#define ct3 PIND.2
unsigned int mode;
//viet ct hien thi hello world ra ngoai man hinh
//viet ct bam ct1 thi hello world hien ra man hinh, ct2 thi xoa
//bam ct1 chu helloworld chay tu trai sang phai man hinh, ct2 chu chay nguoc lai, ct3 thi xoa
//ct1 tung ky tu chay tu trai sang phai va ket thuc khi o cuoi dong, ct 2 thi nguoc lai, ct3 thi hien o dong thu 2 cua man hinh
void main(void)
{
DDRD = 0x00;//cho phep doc pin
PORTD = 0x3C; 
lcd_init(16); //8    
delay_ms(500);
lcd_gotoxy(0,0);
lcd_putsf("hello world");
//lcd_clear();

while (1)
    {
    // Please write your application code here
    if(ct1 == 0 || mode == 1){
        /*delay_ms(250);  
        mode = 1;
        _lcd_write_data(0x1C);  */
        /*lcd_gotoxy(0,0);
        lcd_putsf("hello-world");*/
    }
    if(ct2 == 0 || mode == 2){
        /*delay_ms(250);  
        mode = 2;
        _lcd_write_data(0x18);
        //lcd_clear();     */
    }
    if(ct3 == 0){    
        lcd_clear();
        lcd_gotoxy(0,1);
        lcd_putsf("hello-world");
    }
    }
}
