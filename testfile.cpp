#include "stdlib.h"
#include <bitset>
#include <iostream>

using namespace std;

int main() {
  int x = 0x00000003;
  int y = 0x00000005;
  int xmsb = x >> 31;
  cout << "xmsb: " << bitset<32>(xmsb) << endl;
  int ymsb = y >> 31;
  cout << "ymsb: " << bitset<32>(ymsb) << endl;
  int sum = x + y;
  cout << "sum: " << bitset<32>(sum) << endl;
  int sum_msb = sum >> 31;
  cout << "sum_msb: " << bitset<32>(sum_msb) << endl;
  int overflow = (!xmsb & !ymsb & sum_msb) | (xmsb & ymsb & !sum_msb);
  cout << "overflow: " << bitset<32>(overflow) << endl;
  int not_over = !overflow;
  cout << "not_over: " << bitset<32>(not_over) << endl;
  int neg_over = overflow & sum_msb;
  cout << "neg_over: " << bitset<32>(neg_over) << endl;
  int not_neg = !neg_over;
  cout << "not_neg: " << bitset<32>(not_neg) << endl;
  int max_neg = 0x1 << 31;
  cout << "max_neg: " << bitset<32>(max_neg) << endl;
  int max_pos = ~max_neg;
  cout << "max_pos: " << bitset<32>(max_pos) << endl;
  /*a ? b : c
  overflow ? (negative ? max_neg : max_pos) : sum
  int a = overflow
  int b = negative ? max_neg : max_pos;
  int c = sum;
  int b_a = negative;
  int b_b = max_neg; //0x80000000
  int b_c = max_pos; //0x7fffffff */
  //((-!a) & (c)) | ((-!!a) & (b));
  int a = overflow;
  int bang_a = not_over;
  int neg_bang_a = (~bang_a)+1;
  int c = sum;
  int bang_bang_a = !bang_a;
  int neg_bang_bang_a = (~bang_bang_a)+1;
  int b_a = neg_over;
  int b_b = max_neg;
  int b_c = max_pos;
  int a_2 = neg_over;
  int bang_a_2 = not_neg;
  int neg_bang_a_2 = (~bang_a_2)+1;
  int c_2 = max_pos;
  int bang_bang_a_2 = !bang_a_2;
  int neg_bang_bang_a_2 = (~bang_bang_a_2)+1;
  int b_2 = max_neg;
  int part1 = neg_bang_a & c;
  cout << "part1: " << bitset<32>(part1) << endl;
  int part2 = (neg_bang_a_2 & c_2) | (neg_bang_bang_a_2 & b_2);
  cout << "part2: " << bitset<32>(part2) << endl;
  int part3 = neg_bang_bang_a & part2;
  cout << "part3: " << bitset<32>(part3) << endl;
  int final = part1 | part3;
  cout << "final: " << bitset<32>(final) << endl;
  cout << bitset<32>((((~not_over)+1) & (sum)) | (((~!not_over)+1) & ((((~not_neg)+1) & (max_neg)) | (((~!not_neg)+1) & (max_pos))))) << endl;
  //cout << bitset<32>(((~(not_over+1) & sum) | ((~(!(not_over)+1)) & ((~(not_neg+1)) & max_pos)) | ((~(!(not_neg)+1)) & max_neg))) << endl;
}