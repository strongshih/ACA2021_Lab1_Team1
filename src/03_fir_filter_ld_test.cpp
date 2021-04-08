#include "fir_filter.h"
#include <stdlib.h>
#include <time.h> 
#include <iostream>
#define NUM_SAMPLES	256

using namespace std;

int main () { 
  ap_fixed<8,1> x[NUM_SAMPLES];              //The input x
  ap_fixed<8,1> h[4];                        //The coefficient
  ap_fixed<19,4> y[NUM_SAMPLES];             //The calculated result y
  ap_fixed<19,4> golden_y[NUM_SAMPLES];      //The correct result y
  bool ld;                                   //The load


  for (int i = 0; i < NUM_SAMPLES; i++) {
    x[i] = i * (1.0 / NUM_SAMPLES);
  }

  // **************Test 1*********************
  h[0] = 0.1;
  h[1] = 0.2;
  h[2] = 0.3;
  h[3] = 0.4;

  for (int i = 3; i < NUM_SAMPLES; i++){
    golden_y[i] = h[0] * x[i  ] +
                  h[1] * x[i-1] +
                  h[2] * x[i-2] +
                  h[3] * x[i-3] ;
  }

  for (int i = 0; i < NUM_SAMPLES; i++){

    if(i == 0){
      ld = true;
      fir_filter_ld (x+i, h, y+i, ld);
    }
    else{
      ld = false;
      fir_filter_ld (x+i, h, y+i, ld);
    }
    cout << i << ": " << x[i] << ", " << y[i] << ", " << golden_y[i] << endl;

    if (i >= 3 && y[i] != golden_y[i]){
    	cout << "FAIL!!!" << endl;
    	exit(1);
    }
  }
  // *****************************************

  // **************Test 2*********************
  h[0] = 0.3;
  h[1] = 0.1;
  h[2] = 0.2;
  h[3] = 0.4;

  for (int i = 3; i < NUM_SAMPLES; i++){
    golden_y[i] = h[0] * x[i  ] +
                  h[1] * x[i-1] +
                  h[2] * x[i-2] +
                  h[3] * x[i-3] ;
  }

  for (int i = 0; i < NUM_SAMPLES; i++){

	  if(i == 0){
	        ld = true;
	        fir_filter_ld (x+i, h, y+i, ld);
	      }
	      else{
	        ld = false;
	        fir_filter_ld (x+i, h, y+i, ld);
	      }

    cout << i << ": " << x[i] << ", " << y[i] << ", " << golden_y[i] << endl;

    if (i >= 3 && y[i] != golden_y[i]){
      cout << "FAIL!!!" << endl;
      exit(1);
    }
  }
  // *****************************************

  cout << "SUCCESS!!!" << endl;

};
