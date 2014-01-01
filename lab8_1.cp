#line 1 "D:/projects/mikroc/lab8_1.c"

char keypadPort at PORTD;


sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;
sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;

char text[17];

void main() {
 int citajPrvBroj = 1;
 int broj1 = 0;
 int broj2 = 0;
 int suma;

 ANSEL = 0;
 ANSELH = 0;

 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 do {
 char kp = 0;
 do {
 kp = Keypad_Key_Click();
 } while (kp == 0);

 switch (kp)
 {
 case 1: kp = '1'; break;
 case 2: kp = '2'; break;
 case 3: kp = '3'; break;
 case 4: kp = '+'; break;
 case 5: kp = '4'; break;
 case 6: kp = '5'; break;
 case 7: kp = '6'; break;
 case 8: kp = 'C'; break;
 case 9: kp = '7'; break;
 case 10: kp = '8'; break;
 case 11: kp = '9'; break;
 case 12: kp = '='; break;
 case 13: kp = 'B'; break;
 case 14: kp = '0'; break;
 case 15: kp = 'K'; break;
 case 16: kp = 'P'; break;
 }

 if (kp >= '0' && kp <= '9') {
 if (citajPrvBroj) {
 broj1 = kp - '0';
 } else {
 broj2 = kp - '0';
 }
 } else if (kp == '+') {
 citajPrvBroj = 0;
 } else if (kp == '=') {
 suma = broj1 + broj2;
 } else if (kp == 'B') {
 if (citajPrvBroj) {
 broj1 = 0;
 } else {
 broj2 = 0;
 }
 } else if (kp == 'C') {
 broj1 = broj2 = suma = 0;
 citajPrvBroj = 1;
 Lcd_Cmd(_LCD_CLEAR);
 } else if (kp == 'P') {
 IntToStr(suma, text);
 Lcd_Out_CP(text);
 } else if (kp == 'K') {
 break;
 }
 Lcd_Chr_CP(kp);
 } while (1);
}
