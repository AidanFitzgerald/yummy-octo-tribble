#include "stdlib.h"

int main() {
  int x = 0xE;
  int num = 0xaa;
  int shift2;
  int shift = num << 8;	//1010101000000000
  shift = shift + num; //1010101010101010
  shift2 = shift << 16;
  shift2 = shift2 + shift;
  printf("%d", shift2);
  printf("%d", !(x ^ shift2) );
  return 0;
}