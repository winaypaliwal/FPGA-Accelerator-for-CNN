     #include "ap_fixed.h"
     typedef ap_fixed<12,5,AP_RND, AP_SAT> data_t;
     typedef ap_fixed<9,1,AP_RND, AP_SAT> data_t_fractional;
//     typedef ap_fixed<12,4,AP_RND, AP_SAT> data_t_fractional;

//   typedef ap_fixed<8,2,AP_RND, AP_SAT> data_t_short;
//   typedef ap_fixed<16,6,AP_RND, AP_SAT> data_t_long;

//  typedef float data_t;
//  typedef float data_t_fractional;





#define IMAGE_HEIGHT 32
#define IMAGE_WIDTH 32
#define IMAGE_CHANNELS 1
#define convolved_height 28
#define convolved_width 28
#define convolved_channels  7
#define CLASSES_OUT 10



void dev_digits_classify(
		data_t_fractional input[IMAGE_HEIGHT*IMAGE_WIDTH*IMAGE_CHANNELS],
		data_t_fractional softmax_out[CLASSES_OUT]
);
