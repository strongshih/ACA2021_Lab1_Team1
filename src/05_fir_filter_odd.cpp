#include "fir_filter.h"

void fir_filter_odd (ap_fixed<8,1> *x,
                     ap_fixed<8,1> h[3],
                     ap_fixed<19,4> *y){
  static shift_class<ap_fixed<8,1>,5> regs;
  ap_fixed<19,4> temp = 0;
  ap_fixed<9,2> sum = 0;
  regs << *x;
  MAC:for (int i=0;i<5/2+1;i++){
    if(i==2)
      sum = regs[5/2];//middle tap
    else
      sum = regs[i]+regs[5-1-i];
    temp += h[i]*sum;
  }
  *y = temp;
}