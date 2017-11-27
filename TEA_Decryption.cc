#include <stdio.h>
#include<iostream>
#include<cstdint>

using namespace std;
typedef unsigned int uint32_t;


uint32_t DeltaOne = 0x11111111;
uint32_t DeltaTwo = 0x22222222;

uint32_t KZero = 0x90001C55;
uint32_t KOne = 0x1234ABCD;
uint32_t KTwo = 0xFEDCBA98;
uint32_t KThree = 0xE2468AC0;


uint32_t LZero;
uint32_t RZero;

uint32_t LOne;
uint32_t ROne;

//CipherText
uint32_t LTwo = 0xB72599B2;
uint32_t RTwo = 0xCF8E5A4C;

int main(){
  //Round One
  RZero = RTwo + (-(((LTwo << 4) + KTwo)^(LTwo + DeltaTwo)^((LTwo >> 5) + KThree)));
  //Round Two
  LZero = LTwo + (-(((RZero << 4) + KZero)^(RZero + DeltaOne)^((RZero >> 5) + KOne)));

  printf("%X%X\n", LZero, RZero);

}
