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

//Plaintext
uint32_t LZero = 0xA0000009;
uint32_t RZero = 0x8000006B;

uint32_t LOne;
uint32_t ROne;

uint32_t LTwo;
uint32_t RTwo;

int main(){

  //Round one
  ROne = LZero + (((RZero << 4) + KZero)^((RZero >> 5) + KOne)^(RZero + DeltaOne));
  LTwo = ROne;
  //Round Two
  RTwo = RZero + (((LTwo << 4) + KTwo)^((LTwo >> 5) + KThree)^(LTwo + DeltaTwo));

  printf("%X%X\n", LTwo, RTwo );
}
