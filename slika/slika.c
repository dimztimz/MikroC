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

// ------------------------------------------------------
// GLCD Picture name: lel.bmp
// GLCD Model: KS0108 128x64
// ------------------------------------------------------

const code char lel[1024] = {
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128, 128, 128, 128, 192,  64,  64,  64,  64,  64,  64,  64,  64,  64, 192, 128, 128, 128, 128, 128, 192,  64,  64,  64,  64,  32,  32,  32,  32,  32,  48,  16,  16,  16,  16,  16,  16,  16,  48,  32,  32,  64, 192, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128,  64,  96,  32,  48,  27,  30, 112, 192, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   1,   1,   1, 129, 129, 193,  66,  98,  50,  22, 156, 129, 193,   3,   6,   0,   0,   1,   1,   0,   0,   0,   0,   0,   0,   2,   3,   8,  12,  30,  50,  98, 195, 129,   1,   1,   1,   1,   3,   2,   6,   4,  12,  24,  49, 230, 252,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   4, 198,  98,  34,  35,  97,  65, 128, 128,   0,   0,   0,   0,   0,   0,   0, 224,  63,   6,   4,   4,  12,   8,   8,   8,   8,   8, 248,  16,  16,  16,  16,  16,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 192, 224, 240,  24,  12,   6,  26,  11, 205, 196, 100, 230, 178,  19,   9,   9,  12,   4,   6,   2,   2, 227, 113,  29,   7,   0,   0,   0,   0, 192, 126,  12,  24, 240,   0,   0,   0,   0,   1,  15, 248,   0,   0,   0,   0,   0,   0,   0,   0,   0,   3,  15,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 192,  96,  56,  14,   3,   1,   0,   0,   0,   0,   0,   0,   1,   3,  12,  24,  48,  96, 192, 131,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255,   0,   0,   0,   0,   0,
128, 128, 128,   0,   0,   0,   0, 128,  64,  48,  16, 152, 252,  30,   7,   1,   0, 128,  96,  24,  12,   6,   3,   1,   0,   0,   0,   1,   1,   3,   6,  12,  24,  16, 240, 111,   5,   4,   4,   4,   4,   4, 134, 242,  31,   0,   0,   0,  63, 192,   0,   0,   0,   0,   0, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128, 192,  64,  32,  48,  24,  12,   6,   3,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   3,   6,  12,  24,  48,  32,  96, 192, 128,   0,   0,   1,   0,   0,   0,   0, 128,
  0,   0,   1,   1,   3,  14,  15,  13,   8,   8,   8, 255, 232,  56,  24,  14,   7,   5,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4, 132, 255,   4,   4,   4,   4, 246,  31,   3,   2,   2,   2,   2,   2,   2,   3,  62,  98,  50,  30,   7,   3,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   2,   3,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
  4,   4,  12,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8,   8, 252,  23,  16,  16,  16,  24,  14, 131, 255, 128, 128, 128, 128, 192, 112,  24,   8,   8,   8,  12,   4,   4,   4,   4,   4,   4,  12,   8,   8,  24,  16,  16,  48,  96, 192, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 192,  64,  64,  64,  64,  64,  64,  64,  64,  64, 192, 128, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 192, 112,  16,  24,   8,   8,   8,   8,   8,   8,   8,   8,   8,  12,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  15, 112, 128,  16,  16,  16,  16,  24,  13,  15,  48,  96, 192, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   3,   2,   6,   4,   4,   4,   4,   4,   4,   4,   2,   3,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   3,   6,  12,   8,  24,  16,  48,  32,  32,  32,  32,  32,  32,  48,  16,  24,  12,   4,   6,   3,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
};

void main() {
  ANSEL  = 0; // Configure AN pins as digital
  ANSELH = 0;

  Glcd_Init();
  Glcd_Image(lel);
}