
void main() {
     int i;
     unsigned char sostojba = 0xFF;
     TRISB = 0;
     for (i = 0; i < 5; i++) {
         sostojba = 0xFF;
         PORTB = sostojba;
         Delay_ms(25);
         do {
            sostojba >>= 1;
            PORTB = sostojba;
            Delay_ms(25);
         } while (sostojba != 0);
     }
}