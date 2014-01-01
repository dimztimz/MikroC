#line 1 "D:/projects/mikroc/lab7_1.c"


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

void main() {
 ANSEL = 0;
 ANSELH = 0;

 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_MOVE_CURSOR_RIGHT);
 Lcd_Out_CP("zdravo svetu");
 Lcd_Cmd(_LCD_SECOND_ROW);
 Lcd_Cmd(_LCD_MOVE_CURSOR_RIGHT);
 Lcd_Cmd(_LCD_MOVE_CURSOR_RIGHT);
 Lcd_Out_CP("zdravo svetu");
}
