#include "shift_class.h"
#include "ac_fixed.h"

void fir_filter ( ac_fixed<8,1> *x,
                  ac_fixed<8,1> h[4],
                  ac_fixed<19,4> *y);

void fir_filter_const (ac_fixed<8,1> *x,
                       ac_fixed<19,4> *y);

void fir_filter_ld (ac_fixed<8,1> &x,
                    ac_fixed<8,1> h[4],
                    ac_fixed<19,4> &y,
                    bool &ld);

void fir_filter_even (ac_fixed<8,1> *x,
                      ac_fixed<8,1> h[2],
                      ac_fixed<19,4> *y);

void fir_filter_odd (ac_fixed<8,1> *x,
                     ac_fixed<8,1> h[3],
                     ac_fixed<19,4> *y);

void fir_filter_transposed (ac_fixed<8,1> *x,
                            ac_fixed<8,1> h[4],
                            ac_fixed<19,4> *y);

void fir_filter_systolic (ac_fixed<8,1> *x,
                          ac_fixed<8,1> h[4],
                          ac_fixed<19,4> *y);