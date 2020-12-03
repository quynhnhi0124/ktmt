/*
 * bai_1.c
 *
 * Created: 25-Sep-20 9:43:41 AM
 * Author: QuynhNhi
 */
 //viet chuong trinh dieu khien den led tren board mach
 /*
 den led duoc ket noi vao PE5 (port E bit 5)
 de dieu khien duoc den led thi du lieu phai di tu mcu ra led (output)
 tuy thuoc vao ket noi LED voi MCU la loai nao ma logic xuat ra de dieu khien tuong ung la 0 hoac la 1 de bat den.
    neu noi loai k thi LED sang khi logic xuat ra = 0
    neu noi loai a thi LED sang khi logic xuat ra = 1
    trong mach dien duoc ket noi theo dang k 
 */                                         
 /*
 Trong AVR co 3 thanh ghi tac dong vao tung port
    DDR = data direction = thanh ghi chi huong du lieu
        neu DDR = 1 thi du lieu duoc dieu khien theo huong di tu MCU ra ngoai DV - thiet bi (output)
        neu DDR = 0 thi du lieu duoc dieu khien nhan tu DV - MCU (input)
    PORT la thanh ghi du lieu. Neu 
        port = 1 + output = ghi logic 1 o loi ra(nghia la noi loi ra voi VCC - dien ap nguon duoi = 5V, 3.3V ,...)
        port = 1 + input = loi vao duoc PULL UP (duoc treo len nguon VCC = 5V, 3.3V, ...)
        port = 0 ghi logic 0 o loi ra (nghia la noi loi ra voi GND = 0V)
    PIN la thanh ghi doc du lieu loi vao  
 */                                      
 /*
 De PE5 la loi ra chung ta phai tac dong vao DDR
 DDRE.5 = 1;                                  
 DDRE = 0b0010 0000     
 DDRE = 0x20 x :hex
 vi LED noi theo kieu K nen muon LED sang chung ta phai xuat logic 0V = GND
 PORTE.5 = 0;       
 compile ctrl F9
 */
#include <io.h>

void main(void)
{
DDRE.5 = 0x20;
PORTE = 0x20;
while (1)
    {
    // Please write your application code here
    //PORTE.5 = 0;
    }
}
