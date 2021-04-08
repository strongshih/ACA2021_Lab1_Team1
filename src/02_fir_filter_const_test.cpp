#include "fir_filter.h"
#include <stdlib.h>
#include <time.h> 
#include <iostream>
#define NUM_SAMPLES	256

using namespace std;

int main () { 
  ap_fixed<8,1> x[NUM_SAMPLES];              //The input x
  const ap_fixed<8,1> h[4] = {0.30011, 0.90032, 0.90032, 0.30011}; //The const coefficient
  ap_fixed<19,4> y[NUM_SAMPLES];             //The calculated result y
  ap_fixed<19,4> golden_y[NUM_SAMPLES];      //The correct result y

  for (int i = 0; i < NUM_SAMPLES; i++) {
    x[i] = i * (1.0 / NUM_SAMPLES);
  }

  for (int i = 3; i < NUM_SAMPLES; i++){
    golden_y[i] = h[0] * x[i  ] +
                  h[1] * x[i-1] +
                  h[2] * x[i-2] +
                  h[3] * x[i-3] ;
  }


  for (int i = 0; i < NUM_SAMPLES; i++){
	fir_filter_const (x+i, y+i);
	cout << i << ": " << x[i] << ", " << y[i] << ", " << golden_y[i] << endl;

    if (i >= 3 && y[i] != golden_y[i]){
    	cout << "FAIL!!!" << endl;
    	exit(1);
    }
  }

  cout << "SUCCESS!!!" << endl;

};
