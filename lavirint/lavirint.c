char GLCD_DataPort at PORTD;
sbit GLCD_CS1 at RB0_bit;
sbit GLCD_CS2 at RB1_bit;
sbit GLCD_RS at RB2_bit;
sbit GLCD_RW at RB3_bit;
sbit GLCD_EN at RB4_bit;
sbit GLCD_RST at RB5_bit;
sbit GLCD_CS1_Direction at TRISB0_bit;
sbit GLCD_CS2_Direction at TRISB1_bit;
sbit GLCD_RS_Direction at TRISB2_bit;
sbit GLCD_RW_Direction at TRISB3_bit;
sbit GLCD_EN_Direction at TRISB4_bit;
sbit GLCD_RST_Direction at TRISB5_bit;

void main() {
  ANSEL  = 0;                                      // Configure AN pins as digital
  ANSELH = 0;
  C1ON_bit = 0;                                    // Disable comparators
  C2ON_bit = 0;

  Glcd_Init();

  Glcd_Fill(0x00); //Fill GLCD
  Delay_ms(1);

  do {
    Glcd_Fill(0xFF); //Fill GLCD
    Delay_ms(1);
    Glcd_Fill(0x00); //Clear GLCD
    Delay_ms(1);
    Glcd_Rectangle(5, 5, 40, 40, 1);
    Delay_ms(3);
    Glcd_Fill(0x00);
    Delay_ms(1);
    Glcd_Circle(50, 50, 10, 1);
    Delay_ms(1);
  } while(1);
}

void main2() {
  ANSEL = 0;
        ANSELH = 0;
  Glcd_Init();
  //Glcd_Set_Side(0);
  //Glcd_Set_X(25);
  //Glcd_Set_Page(3);
   //Glcd_Write_Data(45);

   return;
}