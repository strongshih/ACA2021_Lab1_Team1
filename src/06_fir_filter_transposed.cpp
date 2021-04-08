#include "fir_filter.h"

void fir_filter_transposed (ap_fixed<8,1> *x,
                            ap_fixed<8,1> h[4],
                            ap_fixed<19,4> *y){
  static  ap_fixed<19,4> regs[4];
  ap_fixed<19,4> temp = 0;
  MAC:for (int i=3; i>=0; i--) {
    if(i==0)
      temp = 0;
    else
      temp = regs[i-1];
    regs[i] = *x * h[3-i] + temp;
  }
  *y = regs[3];
}