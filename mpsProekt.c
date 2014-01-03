/*Proekt broj 6 po Mikroprocesorski sitemi
student: Dimitrij Mijoski, indeks: 111132
*/
char keypadPort at PORTD;

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
"AMY", "DP1", "GS4", "JV7",
"BNZ", "EQ2", "HT5", "KW8",
"CO0", "FR3", "IU6", "LX9"
};

unsigned int cnt;
unsigned char * textVnesiPoraka = "Vnesi poraka!";
unsigned char cestotaNaBukvi[26];

void interrupt() {
     if (TMR0IF_bit) {
        TMR0 = 131;
        cnt++;
        TMR0IF_bit = 0;
     }
}

unsigned char * IntToStrBezPrazniMesta(int a, unsigned char * outStr) {
         IntToStr(a, outStr);
         while (*outStr != '\0' && *outStr == ' ') {
               outStr++;
         }
         return outStr;
}

void main() {
     unsigned char prethodenZnak = '\0';
     unsigned char tekovenZnak = '\0';
     unsigned char text[40], brojStr[7];
     int i = 0, brZborovi = 0;

     ANSEL = 0;
     ANSELH = 0;
     C1ON_bit = 0;
     C2ON_bit = 0;
     OPTION_REG = 0x83;
     
     Lcd_Init();
     Keypad_Init();
     UART1_Init(9600);

     Lcd_Cmd(_LCD_CLEAR);
     Lcd_Out_CP(textVnesiPoraka);
     Lcd_Cmd(_LCD_SECOND_ROW);

     do {
        prethodenZnak = tekovenZnak;
        do {
           tekovenZnak = Keypad_Key_Click();
        } while (tekovenZnak == 0);
        
        if (tekovenZnak >= 1 && tekovenZnak <=12) {
           if (prethodenZnak >= 1 && prethodenZnak <=12) {
              text[i++] = keypadToLetter[prethodenZnak-1][0];
              Lcd_Chr_CP(text[i-1]);
           } else if (prethodenZnak < 1 || prethodenZnak > 14) {
              brZborovi++;
           }
        } else if (tekovenZnak == 13) {
           if (prethodenZnak >= 1 && prethodenZnak <=12) {
              text[i++] = keypadToLetter[prethodenZnak-1][1];
              Lcd_Chr_CP(text[i-1]);
           }
        } else if (tekovenZnak == 14) {
           if (prethodenZnak >= 1 && prethodenZnak <=12) {
              text[i++] = keypadToLetter[prethodenZnak-1][2];
              Lcd_Chr_CP(text[i-1]);
           }
        } else if (tekovenZnak == 15) {
           if (prethodenZnak >= 1 && prethodenZnak <=12) {
              text[i++] = keypadToLetter[prethodenZnak-1][0];
              Lcd_Chr_CP(text[i-1]);
           }
           text[i++] = ' ';
           Lcd_Chr_CP(text[i-1]);
           UART1_Write(' ');
        } else if (tekovenZnak == 16) {
           unsigned char * brojStrPocetok;
           int j;
        
           if (prethodenZnak >= 1 && prethodenZnak <=12) {
              text[i++] = keypadToLetter[prethodenZnak-1][0];
              Lcd_Chr_CP(text[i-1]);
           }
           text[i] = '\0';
           Lcd_Cmd(_LCD_CLEAR);
           Lcd_Out_CP(text);
           Lcd_Cmd(_LCD_SECOND_ROW);
           
           for (j=0; j<i; j++) {
               if (text[j] >= 'A' && text[j] <= 'Z') {
                  cestotaNaBukvi[text[j]-'A']++;
               }
           }
           brojStrPocetok = IntToStrBezPrazniMesta(brZborovi, brojStr);
           strcpy(text, "Ima ");
           strcat(text, brojStrPocetok);
           strcat(text, " zborovi.");
           Lcd_Out_CP(text);
           
           for (j=0; j<26; j++) {
               if (cestotaNaBukvi[j] != 0) {
                   brojStrPocetok = IntToStrBezPrazniMesta(cestotaNaBukvi[j], brojStr);
                   UART1_Write(j+'A');
                   UART1_Write(' ');
                   UART1_Write_Text(brojStrPocetok);
                   UART1_Write(' ');
               }
           }
           
           INTCON = 0xA0;
           cnt = 0;
           TMR0 = 131;
           while (cnt < 20);
           INTCON = 0;

           i = 0;
           brZborovi = 0;
           for (j=0; j<26; j++) {
               cestotaNaBukvi[j] = 0;
           }
           Lcd_Cmd(_LCD_CLEAR);
           Lcd_Out_CP(textVnesiPoraka);
           Lcd_Cmd(_LCD_SECOND_ROW);
        }
     } while (prethodenZnak != 15 || tekovenZnak != 15);
}