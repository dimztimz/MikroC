void main() {

    unsigned char a = 1;
    ANSEL = 0;
    ANSELH = 0;
    //C1ON_bit = 0;
    //C2ON_bit = 0;
    TRISA = 0xff;
    //TRISA0_bit = 1;
    TRISB = 0x00;

    while(PORTA == 0) {

        PORTB = a;
        a = (a<<1);
        if (a == 0) a = 1;
    }
}
