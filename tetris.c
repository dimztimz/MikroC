
// Start LCD module connections
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

const char character[] = {4,4,14,21,14,4,4,0};

void CustomChar(char pos_row, char pos_char) {
  char i;
    Lcd_Cmd(64);
    for (i = 0; i<=7; i++) Lcd_Chr_CP(character[i]);
    Lcd_Cmd(_LCD_RETURN_HOME);
    //Lcd_Chr(1,1, 0);
    //Lcd_Chr(1,2, 0);
    //Lcd_Chr(1,3, 0);
    Lcd_Chr_CP(0);
    //Lcd_Cmd(_LCD_RETURN_HOME);
    //Lcd_Chr(pos_row, pos_char, 0);
}

int sostojba[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int sostojba2[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned char figura[] = {0,0,0,0};

void orSostojbaFigura(int * inSostojba, unsigned char * fig, int * outSostojba,
     int x, int y) {
     int i, iFig, iGran;
     for(i=0; i<16; i++) {
              outSostojba[i] = inSostojba[i];
     }
     if (y < 0) {
        i = 0;
        iFig = -y;
     } else {
       i = y;
       iFig = 0;
     }
     iGran = y + 4;
     if (iGran > 16) {
        iGran = 16;
     }
     for (; i<iGran; i++, iFig++) {
         outSostojba[i] |= (int)fig[iFig] << x;
     }
}

void prikaziSostojba(int * s) {
     unsigned char znak1[8];
     unsigned char znak2[8];
     unsigned char znak3[8];
     unsigned char znak4[8];
     int x, y;
     for(y = 0; y < 8; y++) {
           znak4[7-y] = s[y] & 0x1F;
           znak3[7-y] = (s[y] >> 5) & 0x1F;
           znak2[7-y] = (s[y+8]) & 0x1F;
           znak1[7-y] = (s[y+8] >> 5) & 0x1F;
     }
     Lcd_Cmd(64);
     for (y = 0; y<8; y++) Lcd_Chr_CP(znak1[y]);
     Lcd_Cmd(_LCD_RETURN_HOME);
     Lcd_Chr(1, 1, 0);

     Lcd_Cmd(64);
     for (y = 0; y<8; y++) Lcd_Chr_CP(znak2[y]);
     Lcd_Cmd(_LCD_RETURN_HOME);
     Lcd_Chr(1, 2, 0);
     
     Lcd_Cmd(64);
     for (y = 0; y<8; y++) Lcd_Chr_CP(znak3[y]);
     Lcd_Cmd(_LCD_RETURN_HOME);
     Lcd_Chr(2, 1, 0);
     
     Lcd_Cmd(64);
     for (y = 0; y<8; y++) Lcd_Chr_CP(znak4[y]);
     Lcd_Cmd(_LCD_RETURN_HOME);
     Lcd_Chr(2, 2, 0);
}

void main() {
     int y = 15;

     ANSEL = 0;
     ANSELH = 0;
     Lcd_Init();
     Lcd_Cmd(_LCD_CURSOR_OFF);
     sostojba[15] = 0b0000000000;
     sostojba[14] = 0b0000000000;
     sostojba[13] = 0b0000000000;
     sostojba[12] = 0b0000000000;
     sostojba[11] = 0b0000000000;
     sostojba[10] = 0b0000000000;
     sostojba[9]  = 0b0000000000;
     sostojba[8]  = 0b0000000000;
     sostojba[7]  = 0b0000000000;
     sostojba[6]  = 0b0000000000;
     sostojba[5]  = 0b0000000000;
     sostojba[4]  = 0b0000000000;
     sostojba[3]  = 0b0000011010;
     sostojba[2]  = 0b0000011010;
     sostojba[1]  = 0b0100011011;
     sostojba[0]  = 0b1110111111;
     
     figura[3] = 0b0000;
     figura[2] = 0b0011;
     figura[1] = 0b0010;
     figura[0] = 0b0010;
     
     for (y = 3; y >= -3; y--) {
         orSostojbaFigura(sostojba, figura, sostojba2, 6, y);
         prikaziSostojba(sostojba2);
     }
}