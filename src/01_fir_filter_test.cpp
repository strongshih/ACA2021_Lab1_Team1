#include "fir.h"
#include <stdlib.h>
#include <time.h> 
#include <iostream>
#define NUM_SAMPLES	16

using namespace std;

int main () { 
  ac_fixed<8,1> x[NUM_SAMPLES];
  ac_fixed<8,1> h[4] = {0.1,0.2,0.3,0.4};
  ac_fixed<19,4> y[NUM_SAMPLES];
  ac_fixed<19,4> ans[NUM_SAMPLES];
  srand( time(NULL) );

  for (int i = 0; i < NUM_SAMPLES; i++) {
//    double t = (double) rand() / (RAND_MAX + 1.0);
    x[i] = i * 0.0625;
  }

  for (int i = 3; i < NUM_SAMPLES; i++){
	  ans[i] = h[0] * x[i  ] +
			   h[1] * x[i-1] +
			   h[2] * x[i-2] +
			   h[3] * x[i-3] ;
  }


  for (int i = 0; i < NUM_SAMPLES; i++){
	fir_filter (x+i, h, y+i);
	cout << i << ": " << x[i] << ", " << y[i] << ", " << ans[i] << endl;
    if (i >= 3 && y[i] != ans[i]){
    	cout << "FAIL!!!" << endl;
    	exit(1);
    }
  }

  cout << "SUCCESS!!!" << endl;

};
