#line 1 "D:/projects/mikroc/lab6_1.c"

unsigned cnt = 0;

void interrupt() {
 if (TMR0IF_bit != 0) {
 cnt++;
 TMR0IF_bit = 0;
 TMR0 = 131;
 }
}

void main() {
 unsigned char red1 = 0b00010001;
 unsigned char red2 = 0b00011011;
 unsigned char red3 = 0b00010101;
 unsigned char red4 = 0b00010001;

 OPTION_REG = 0x83;
 ANSEL = 0;
 ANSELH = 0;
 C1ON_bit = 0;
 C2ON_bit = 0;

 TRISA = 0;
 TRISB = 0;
 TRISC = 0;
 TRISD = 0;

 INTCON = 0x20;

 while (1) {
 PORTA = red1;
 PORTB = red2;
 PORTC = red3;
 PORTD = red4;

 cnt = 0;
 TMR0 = 131;
 while (cnt < 25) {}

 red1 = (red1 << 1) | (red1 >> 7);
 red2 = (red2 << 1) | (red2 >> 7);
 red3 = (red3 << 1) | (red3 >> 7);
 red4 = (red4 << 1) | (red4 >> 7);

 }
}
