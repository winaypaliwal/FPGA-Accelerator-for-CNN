#include <iostream>

#include "dev_digits.h"
#include "operators.h"

#include "weights_biases.h"







void dev_digits_classify(
		data_t_fractional input[IMAGE_HEIGHT*IMAGE_WIDTH*IMAGE_CHANNELS],
		data_t_fractional softmax_out[CLASSES_OUT]
){
#pragma HLS INTERFACE s_axilite port=input bundle=a
#pragma HLS INTERFACE s_axilite port=softmax_out bundle=a
#pragma HLS INTERFACE s_axilite port=return bundle=a
  // data_t convolved_out[28*28*7];
  // data_t relu_activated_convolved_out[28*28*36];
  data_t max_pooled_out[7*7*7];
  // data_t relu_activated_max_pooled_out[14*14*36];
  data_t condensed_64_out[64];
  // data_t relu_activated_condensed_128_out[128];
  data_t condensed_10_out[CLASSES_OUT];



//#pragma HLS pipeline


  convolve(input,max_pooled_out, weights_convolution, biases_convolution);
  // relu_activate_convolved(convolved_out);


  // max_pool(convolved_out, max_pooled_out); //Also ReLu activates
  // relu_activate(max_pooled_out, 7*7*7);

  densifyto64(max_pooled_out, condensed_64_out,weights_dense64, biases_dense64); //Also ReLu activates
  // relu_activate(condensed_64_out, 64);


//  densify64to10(condensed_64_out, condensed_10_out,weights_dense10, biases_dense10); //Also Softmax activates
  // softmax_activate(condensed_10_out, softmax_out, 10);
//  data_t in[], data_t out[10], data_t_fractional weights[], data_t_fractional biases[]){
  //#pragma HLS PIPELINE
    data_t element;
    for(int j = 0; j < 10; j++) {
  #pragma HLS unroll
    	condensed_10_out[j] = biases_dense10[j];
    }
    for(int i = 0; i < 64; i++) {
  #pragma HLS unroll factor=2
        element = condensed_64_out[i];
        for(int j = 0; j < 10; j++) {
        int index = i*10+j;
        condensed_10_out[j] += element * weights_dense10[index];
        }
    }

    data_t sum = 0;
    for(int i = 0; i < 10; i++){
  //#pragma HLS unroll
    	condensed_10_out[i] = std::exp((float)condensed_10_out[i]);
        sum = sum + condensed_10_out[i];
    }
      for(int i = 0; i < 10; i++){
//    #pragma HLS unroll
    	  softmax_out[i] = condensed_10_out[i] / sum ;

      }





}
