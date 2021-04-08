#include "fir_filter.h"
#include <stdlib.h>
#include <time.h> 
#include <iostream>
#define NUM_SAMPLES	256

using namespace std;

int main () { 
  ap_fixed<8,1> x[NUM_SAMPLES];              //The input x
  ap_fixed<8,1> h[4] = {0.1, 0.2, 0.3, 0.4}; //The coefficient
  ap_fixed<19,4> y[NUM_SAMPLES];             //The calculated result y
  ap_fixed<19,4> golden_y[NUM_SAMPLES];      //The correct result y

  for (int i = 0; i < NUM_SAMPLES; i++) {
    x[i] = i * (1.0 / NUM_SAMPLES);
  }

  for (int i = 3; i < NUM_SAMPLES; i++){
    golden_y[i] = h[0] * x[i-3] +
                  h[1] * x[i-2] +
                  h[2] * x[i-1] +
                  h[3] * x[i-0] ;
  }

  for (int i = 0; i < NUM_SAMPLES; i++){
	  fir_filter_systolic (x+i, h, y+i);
  }

  for (int i = 9; i < NUM_SAMPLES; i++){

	  if (y[i] != golden_y[i-6]){
      cout << "FAIL!!!" << endl;
      exit(1);
    }
  }

  cout << "SUCCESS!!!" << endl;

};
