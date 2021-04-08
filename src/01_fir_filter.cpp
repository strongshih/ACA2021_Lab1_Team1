#include "fir_filter.h"

void fir_filter ( ap_fixed<8,1> *x,
                  ap_fixed<8,1> h[4],
                  ap_fixed<19,4> *y){
  static shift_class<ap_fixed<8,1>,4> regs;
  ap_fixed<19,4> temp = 0;
  regs << *x;
  MAC:for (int i = 0; i<4; i++) { 
    temp += h[i]*regs[i];
  } 
  *y = temp;
}
