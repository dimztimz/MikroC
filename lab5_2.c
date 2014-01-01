void main() {
     unsigned char sostojba;
     TRISB = 0;
     TRISC = 0;
     
     while (1) {
           sostojba = 1;
           do {
              PORTB = sostojba;
              Delay_ms(25);
              PORTB = 0;
              sostojba <<= 1;
              PORTC = sostojba;
              Delay_ms(25);
              PORTC = 0;
              sostojba <<= 1;
           } while (sostojba != 0);
     }
}