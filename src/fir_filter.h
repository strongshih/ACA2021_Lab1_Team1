#include "shift_class.h"
#include "ap_fixed.h"

void fir_filter ( ap_fixed<8,1> *x,
                  ap_fixed<8,1> h[4],
                  ap_fixed<19,4> *y);

void fir_filter_const (ap_fixed<8,1> *x,
                       ap_fixed<19,4> *y);

void fir_filter_ld (ap_fixed<8,1> *x,
                    ap_fixed<8,1> h[4],
                    ap_fixed<19,4> *y,
                    bool &ld);

void fir_filter_even (ap_fixed<8,1> *x,
                      ap_fixed<8,1> h[2],
                      ap_fixed<19,4> *y);

void fir_filter_odd (ap_fixed<8,1> *x,
                     ap_fixed<8,1> h[3],
                     ap_fixed<19,4> *y);

void fir_filter_transposed (ap_fixed<8,1> *x,
                            ap_fixed<8,1> h[4],
                            ap_fixed<19,4> *y);

void fir_filter_systolic (ap_fixed<8,1> *x,
                          ap_fixed<8,1> h[4],
                          ap_fixed<19,4> *y);
