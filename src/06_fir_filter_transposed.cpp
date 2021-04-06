#include "fir_filter.h"
void fir_filter_transposed (ac_fixed<8,1> *x,
                            ac_fixed<8,1> h[4],
                            ac_fixed<19,4> *y){
  static  ac_fixed<19,4> regs[4];
  ac_fixed<19,4> temp = 0;
  MAC:for (int i=3; i>=0; i--) {
    if(i==0)
      temp = 0;
    else
      temp = regs[i-1];
    regs[i] = *x * h[3-i] + temp;
  }
  *y = regs[3];
}