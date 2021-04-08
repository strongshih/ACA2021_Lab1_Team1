#include "fir_filter.h"

void fir_filter_ld (ap_fixed<8,1> *x,
                    ap_fixed<8,1> h[4],
                    ap_fixed<19,4> *y,
                    bool &ld){
  static shift_class<ap_fixed<8,1>,4> regs;
  ap_fixed<19,4> temp = 0;
  static ap_fixed<8,1> h_int[4];
  if(ld==true)
    for(int i=0;i<4;i++)
      h_int[i] = h[i];
  regs << *x;
  MAC:for (int i = 0; i<4; i++) {
    temp += h_int[i]*regs[i];
  }
  *y = temp;
}
