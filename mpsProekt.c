
unsigned char keypadPort at PORTD;

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

char keypadToLetter[][4] = {
"AMY", "DPY", "GS4", "JV7",
"BNZ", "EQ2", "HT5", "KW8",
"CO0", "FR3", "IU6", "LX9"
};

unsigned int cnt;

void interrupt() {
     if (TMR0IF_bit) {
        TMR0 = 131;
        cnt++;
        TMR0IF_bit = 0;
     }
}


void main() {
     unsigned char prethodenZnak = '\0';
     unsigned char tekovenZnak = '\0';
     unsigned char text[40];
     int i = 0;

     ANSEL = 0;
     ANSELH = 0;
     C1ON_bit = 0;
     C2ON_bit = 0;
     
     Lcd_Init();
     Keypad_Init();
     UART1_Init(9600);

     do {
        prethodenZnak = tekovenZnak;
        do {
           tekovenZnak = Keypad_Key_Click();
        } while (tekovenZnak == 0);
        if (tekovenZnak >= 1 && tekovenZnak <=12) {
           if (prethodenZnak >= 1 && prethodenZnak <=12) {
              text[i++] = keypadToLetter[prethodenZnak-1][0];
           }
        } else if (tekovenZnak == 13) {
           if (prethodenZnak >= 1 && prethodenZnak <=12) {
              text[i++] = keypadToLetter[prethodenZnak-1][1];
           }
        } else if (tekovenZnak == 14) {
           if (prethodenZnak >= 1 && prethodenZnak <=12) {
              text[i++] = keypadToLetter[prethodenZnak-1][2];
           }
        } else if (tekovenZnak == 15) {
           if (prethodenZnak >= 1 && prethodenZnak <=12) {
              text[i++] = keypadToLetter[prethodenZnak-1][0];
           }
           text[i++] = ' ';
        }  else if (tekovenZnak == 16) {
           if (prethodenZnak >= 1 && prethodenZnak <=12) {
              text[i++] = keypadToLetter[prethodenZnak-1][0];
           }
           text[i++] = '\0';
           Lcd_Cmd(_LCD_CLEAR);
           Lcd_Out_CP(text);
        }
        
        
        
     } while (prethodenZnak == 15 && tekovenZnak == 15);
}