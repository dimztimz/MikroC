#include <string.h>
#include <stdlib.h>

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

#define GORE(x) (x & 1)
#define DESNO(x) (x & 2)
#define DOLU(x) (x & 4)
#define LEVO(x) (x & 8)
#define IGRAC(x) (x & 16)

#define SET_GORE(x) (x | 1)
#define SET_DESNO(x) (x | 2)
#define SET_DOLU(x) (x | 4)
#define SET_LEVO(x) (x | 8)
#define SET_IGRAC(x) (x | 16)

void printCellWithPlayer(unsigned char cellModel)
{
  unsigned char vertLine = 0;
  if (LEVO(cellModel)) {
    vertLine = 0xFF;
  }
  if (GORE(cellModel)) {
    vertLine |= 1;
  }
  if (DOLU(cellModel)) {
    vertLine |= 0x80;
  }
  Glcd_Write_Data(vertLine); //1
  vertLine &= 0x81; //unset middle six bytes
  Glcd_Write_Data(vertLine); //2
  Glcd_Write_Data(vertLine);
  if (IGRAC(cellModel)) {
    vertLine |= 0x18; //set two middle bits
  }
  Glcd_Write_Data(vertLine);
  Glcd_Write_Data(vertLine);
  vertLine &= 0b11100111; //unset two middle bits
  Glcd_Write_Data(vertLine);
  Glcd_Write_Data(vertLine);
  if (DESNO(cellModel)) {
    vertLine = 0xFF;
  }
  Glcd_Write_Data(vertLine);
}

void printCell(unsigned char cellModel)
{
  unsigned i = 0;
  unsigned char vertLine = 0;

  if (LEVO(cellModel)) {
    vertLine = 0xFF;
    Glcd_Write_Data(vertLine);
    ++i;
  }
  vertLine = 0;
  if (GORE(cellModel)) {
    vertLine |= 1;
  }
  if (DOLU(cellModel)) {
    vertLine |= 0x80;
  }
  for (; i < 7; ++i) {
    Glcd_Write_Data(vertLine);
  }
  if (DESNO(cellModel)) {
    vertLine = 0xFF;
  }
  Glcd_Write_Data(vertLine);
  ++i;
}

#define MZ(x, y) ((x) | ((y) << 4))

unsigned char maze[8][8] =
{
{MZ(9, 3), MZ(9, 5), MZ(5, 5), MZ(1, 2), MZ(9, 5), MZ(3, 9), MZ(3, 9), MZ(3, 11)},
{MZ(10, 10), MZ(12, 1), MZ(5, 7), MZ(10, 12), MZ(6, 11), MZ(10, 10), MZ(12, 6), MZ(12, 2)},
{MZ(14, 10), MZ(11, 10), MZ(9, 3), MZ(12, 3), MZ(9, 6), MZ(10, 10), MZ(9, 5), MZ(3, 10)},
{MZ(9, 6), MZ(8, 6), MZ(10, 10), MZ(9, 6), MZ(12, 5), MZ(2, 14), MZ(12, 3), MZ(12, 6)},
{MZ(10, 9), MZ(0, 5), MZ(6, 14), MZ(12, 5), MZ(3, 13), MZ(4, 3), MZ(9, 6), MZ(9, 3)},
{MZ(12, 2), MZ(14, 9), MZ(3, 9), MZ(5, 3), MZ(10, 9), MZ(3, 10), MZ(12, 3), MZ(10, 10)},
{MZ(9, 2), MZ(9, 6), MZ(10, 12), MZ(7, 10), MZ(10, 10), MZ(14, 8), MZ(1, 6), MZ(14, 10)},
{MZ(14, 12), MZ(6, 13), MZ(4, 5), MZ(5, 6), MZ(10, 12), MZ(5, 6), MZ(12, 5), MZ(5, 6)}
};

void printMaze()
{
  unsigned i, j;
  for(i = 0; i < 8; ++i) {
    Glcd_Set_Side(64);
    Glcd_Set_Page(i);
    Glcd_Set_X(0);
    for(j = 0; j < 4; ++j) {
      printCell(maze[i][j] & 0x0F);
      printCell((maze[i][j] & 0xF0) >> 4);
    }
    Glcd_Set_Side(0);
    Glcd_Set_Page(i);
    Glcd_Set_X(0);
    for(; j < 8; ++j) {
      printCell(maze[i][j] & 0x0F);
      printCell((maze[i][j] & 0xF0) >> 4);
    }
  }
}

void main() {
  unsigned i, j;
  ANSEL  = 0;                                      // Configure AN pins as digital
  ANSELH = 0;
  C1ON_bit = 0;                                    // Disable comparators
  C2ON_bit = 0;

  Glcd_Init();

  //Glcd_Fill(0x00); //Fill GLCD
  //Delay_ms(1);
  
  for (i = 0; i < 8; ++i) {
    for (j = 0; j < 8; ++j) {
      //maze[i][j] = rand();
    }
  }
  printMaze();
}