#include "fir_filter.h"

void fir_filter_const (ap_fixed<8,1> *x,
                       ap_fixed<19,4> *y){
  const ap_fixed<8,1> h[4] = {0.30011, 0.90032, 0.90032, 0.30011};
  static shift_class<ap_fixed<8,1>,4> regs;
  ap_fixed<19,4> temp = 0;
  regs << *x;
  MAC:for (int i = 0; i<4; i++) {
    temp += h[i]*regs[i];
  }
  *y = temp;
}