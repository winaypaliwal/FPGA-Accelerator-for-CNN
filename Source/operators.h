#include <cstdlib>
#include <math.h>
#include <complex>

#include "dev_digits.h"

#define filter_h  5
#define filter_w  5
#define pooled_dim 7

//Zero Padding, 1x1 Strides
void convolve(data_t_fractional in[],data_t (&outpool)[7*7*7], data_t_fractional weights[], data_t_fractional biases[]){

      for(int out_channel = 0; out_channel < convolved_channels; out_channel++) {
//#pragma HLS unroll factor=98
        // data_t pool_window_column[4];
        for(int out_y = 0; out_y < convolved_height; out_y++) {
            data_t pool_window_row[4];
            for(int out_x = 0; out_x < convolved_width; out_x++) {

//#pragma HLS loop_flatten
                  int index_acc = out_y*convolved_width*convolved_channels
                                + out_x*convolved_channels
                                + out_channel;
                  data_t current_el = biases[out_channel];
                  for(int in_channel = 0; in_channel < IMAGE_CHANNELS; in_channel++){
                      for(int filter_y = 0; filter_y < filter_h; filter_y++){
#pragma HLS unroll
                          for(int filter_x = 0; filter_x < filter_w; filter_x++){
//#pragma HLS loop_flatten


                              int index_weight = filter_y*filter_w*IMAGE_CHANNELS*convolved_channels
                                               + filter_x*IMAGE_CHANNELS*convolved_channels
                                               + in_channel*convolved_channels
                                               + out_channel;


                              int index_data = (out_y*1+filter_y-0)*IMAGE_WIDTH*IMAGE_CHANNELS
                                             + (out_x*1+filter_x-0)*IMAGE_CHANNELS
                                             + in_channel;

                              current_el += in[index_data] * weights[index_weight];

                          }
                      }
                  }
                  // if (current_el > 0)
                  //   out[index_acc] = current_el;
                  // else
                  //   out[index_acc] = 0;
                  pool_window_row[out_x % 4] = current_el;
                  if(out_x % 4 == 3){
                    data_t max;
                    if(out_y % 4 == 0){
                      max = 0;
                      for(int i = 0; i < 4; i++){
#pragma HLS unroll
                        if(pool_window_row[i] > max)
                        max = pool_window_row[i];
                      }
                      outpool[(out_y/4) * pooled_dim * convolved_channels + (out_x/4)* convolved_channels + out_channel] = max;
                    }else{
                      data_t max_y = outpool[(out_y/4) * pooled_dim * convolved_channels + (out_x/4)* convolved_channels + out_channel];
                      max = 0;
                      for(int i = 0; i < 4; i++){
#pragma HLS unroll
                        if(pool_window_row[i] > max)
                        max = pool_window_row[i];
                      }
                      if (max > max_y)
                        outpool[(out_y/4) * pooled_dim * convolved_channels + (out_x/4)* convolved_channels + out_channel] = max;
                  }

              }



          }
      }
  }

}







// void relu_activate_convolved(data_t (&in)[28*28*7]){
// //#pragma HLS inline
//   for (int i=0; i<28*28*7; i++) {
//       if (in[i] > 0) continue;
//       else in[i] = 0;
//   }
// }

//Stride 4x4, Pool 4x4
// void max_pool(data_t in[], data_t (&out)[7*7*7]) {
// ////#pragma HLS PIPELINE
//
//   //Looping over input channels
// //#pragma HLS unroll factor= 49
//   for(int input_channel_number = 0; input_channel_number < convolved_channels; input_channel_number++){
// 	  // Vertical Strides of 2 over input
// 	  for(int y_input = 0; y_input < convolved_height; y_input += 4){
// 		  // Horizontal Strides of 2 over input
// 		  for(int x_input = 0; x_input < convolved_width; x_input += 4){
// 			  // Get 2x2 matrix to be pooled
// ////#pragma HLS PIPELINE
// 			  data_t max = in[y_input * convolved_width * convolved_channels + x_input * convolved_channels + input_channel_number];;
// 			  data_t el;
// 			  for(int y_pool = 0; y_pool < 4; y_pool++){
// 				  for(int x_pool = 0; x_pool < 4; x_pool++){
// //#pragma HLS loop_flatten
// 					  el = in[(y_input + y_pool) * convolved_width * convolved_channels + (x_input + x_pool) * convolved_channels + input_channel_number];
//   					  if( el > max)
//   						  max = el;
//
// 				  }
// 			  }
// 			  out[(y_input/4) * pooled_dim * convolved_channels + (x_input/4)* convolved_channels + input_channel_number] =  max;
//
// 		  }
// 	  }
//   }
//
// }




void densifyto64(data_t in[], data_t (&out)[64], data_t_fractional weights[], data_t_fractional biases[]){
////#pragma HLS PIPELINE
	data_t element;
  for(int j = 0; j < 64; j++) {
#pragma HLS unroll
    out[j] = biases[j];
  }
  for(int i = 0; i < 7*7*7; i++) {
#pragma HLS unroll factor=49

      element = in[i];
      for(int j = 0; j < 64; j++) {
#pragma HLS unroll factor = 2
        out[j] += element * weights[i*64+j];
      }
  }


  for(int i = 0; i < 64; i++){
#pragma HLS unroll
      if (out[i] > 0) continue;
      else out[i] = 0;
  }
}

//void densify64to10(data_t in[], data_t out[10], data_t_fractional weights[], data_t_fractional biases[]){
////#pragma HLS PIPELINE
//  data_t element;
//  for(int j = 0; j < 10; j++) {
//#pragma HLS unroll
//    out[j] = biases[j];
//  }
//  for(int i = 0; i < 64; i++) {
//#pragma HLS unroll factor=2
//      element = in[i];
//      for(int j = 0; j < 10; j++) {
//      int index = i*10+j;
//      out[j] += element * weights[index];
//      }
//  }
//
//  data_t sum = 0;
//  for(int i = 0; i < 10; i++){
////#pragma HLS unroll
//      out[i] = std::exp((float)out[i]);
//      sum = sum + out[i];
//  }

  // Cast to Probabilities
//  for(int i = 0; i < 10; i++){
//#pragma HLS unroll
//    out[i] = out[i] / sum ;
//
//  }
//}


// void softmax_activate(data_t in[], data_t out[], int length){
//   data_t sum = 0;
// //#pragma HLS PIPELINE
//   for(int i = 0; i < length; i++){
//     out[i] = std::exp((float)in[i]);
//     sum = sum + out[i];
//   }
//   // Cast to Probabilities
//   for(int i = 0; i < length; i++){
//     out[i] = out[i] / sum ;
//
//   }
//
//
// }
