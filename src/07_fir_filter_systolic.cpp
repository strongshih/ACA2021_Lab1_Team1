#include "pe_class.hpp"
#include "fir_filter.h"

void fir_filter_systolic (ap_fixed<8,1> *x,
                          ap_fixed<8,1> h[4],
                          ap_fixed<19,4> *y){
  static pe_class<ap_fixed<8,1>,ap_fixed<8,1>,ap_fixed<19,4> > pe[4];
  ap_fixed<8,1> x_int[4];
  ap_fixed<19,4> y_int[4];
  ap_fixed<19,4> tmp = 0;

  CONN:for(int i=0;i<4;i++)
         if(i==0)
           pe[0].exec(        *x, h[i], tmp,x_int[i],          y_int[i]);
         else
           pe[i].exec(x_int[i-1], h[i],   y_int[i-1],x_int[i] ,y_int[i]);
  *y = y_int[3];
}
