#include "fir_filter.h"
#include "shift_class.h"
void fir_filter_const (ac_fixed<8,1> *x,
                       ac_fixed<19,4> *y){
  const ac_fixed<8,1> h[4] = {0.30011, 0.90032, 0.90032, 0.30011};
  static shift_class<ac_fixed<8,1>,4> regs;
  ac_fixed<19,4> temp = 0;
  regs << *x;
  MAC:for (int i = 0; i<4; i++) {
    temp += h[i]*regs[i];
  }
  *y = temp;
}