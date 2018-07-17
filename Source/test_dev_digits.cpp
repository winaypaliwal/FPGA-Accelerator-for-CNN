#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "dev_digits.h"
#include "test_data100_newformat.h"

#include <time.h>
unsigned int tsdelta(struct timespec* start, struct timespec* end)
{
	unsigned int x = end->tv_nsec - start->tv_nsec;
	unsigned int y = end->tv_sec - start->tv_sec;
	return (y * 1000000000 + x);

}

int main(int argc, char **argv)
{

  //6
  data_t_fractional input[IMAGE_HEIGHT*IMAGE_WIDTH*IMAGE_CHANNELS] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.043137254901960784, 0.0196078431372549, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.00392156862745098, 0.0, 0.0, 0.0, 0.07450980392156863, 0.7254901960784313, 0.5450980392156862, 0.25098039215686274, 0.11372549019607843, 0.03137254901960784, 0.00392156862745098, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0392156862745098, 0.20784313725490197, 0.34901960784313724, 0.21176470588235294, 0.043137254901960784, 0.00392156862745098, 0.396078431372549, 1.0, 1.0, 0.9803921568627451, 0.9098039215686274, 0.6980392156862745, 0.26666666666666666, 0.08235294117647059, 0.023529411764705882, 0.0196078431372549, 0.00784313725490196, 0.00392156862745098, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.6627450980392157, 0.9803921568627451, 1.0, 0.9647058823529412, 0.7843137254901961, 0.5019607843137255, 0.796078431372549, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.8588235294117647, 0.7215686274509804, 0.6941176470588235, 0.5411764705882353, 0.4549019607843137, 0.22745098039215686, 0.0784313725490196, 0.0196078431372549, 0.00392156862745098, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.9686274509803922, 0.8470588235294118, 0.6666666666666666, 0.28627450980392155, 0.027450980392156862, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.9647058823529412, 0.611764705882353, 0.08235294117647059, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.9490196078431372, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5490196078431373, 0.00392156862745098, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.20784313725490197, 0.4549019607843137, 0.5647058823529412, 0.7215686274509804, 0.8705882352941177, 0.9921568627450981, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.9411764705882353, 0.9647058823529412, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.8549019607843137, 0.01568627450980392, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.00392156862745098, 0.00784313725490196, 0.03137254901960784, 0.19607843137254902, 0.9490196078431372, 1.0, 1.0, 0.9686274509803922, 0.8823529411764706, 0.7843137254901961, 0.8352941176470589, 0.6235294117647059, 0.4588235294117647, 0.1568627450980392, 0.19215686274509805, 0.3176470588235294, 0.3333333333333333, 0.4627450980392157, 0.7176470588235294, 0.9686274509803922, 1.0, 1.0, 0.7215686274509804, 0.00784313725490196, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.011764705882352941, 0.6078431372549019, 1.0, 1.0, 0.7843137254901961, 0.23137254901960785, 0.09411764705882353, 0.047058823529411764, 0.09019607843137255, 0.01568627450980392, 0.00784313725490196, 0.0, 0.0, 0.0, 0.0, 0.00392156862745098, 0.050980392156862744, 0.2196078431372549, 0.4392156862745098, 0.4745098039215686, 0.1450980392156863, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.09803921568627451, 0.9607843137254902, 1.0, 0.8627450980392157, 0.13333333333333333, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.00392156862745098, 0.00784313725490196, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.29411764705882354, 1.0, 0.996078431372549, 0.3411764705882353, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5019607843137255, 1.0, 0.8431372549019608, 0.0392156862745098, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5568627450980392, 1.0, 0.596078431372549, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5333333333333333, 1.0, 0.5607843137254902, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.4235294117647059, 1.0, 0.7764705882352941, 0.023529411764705882, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.27058823529411763, 1.0, 0.9882352941176471, 0.47843137254901963, 0.011764705882352941, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.07450980392156863, 0.9215686274509803, 1.0, 0.9686274509803922, 0.44313725490196076, 0.0392156862745098, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.00392156862745098, 0.5568627450980392, 1.0, 1.0, 0.9882352941176471, 0.6784313725490196, 0.1411764705882353, 0.011764705882352941, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0784313725490196, 0.7725490196078432, 1.0, 1.0, 1.0, 0.9058823529411765, 0.592156862745098, 0.2235294117647059, 0.011764705882352941, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.12549019607843137, 0.7529411764705882, 0.9921568627450981, 1.0, 1.0, 1.0, 0.9333333333333333, 0.5490196078431373, 0.23529411764705882, 0.047058823529411764, 0.00784313725490196, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.01568627450980392, 0.058823529411764705, 0.043137254901960784, 0.00392156862745098, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.07058823529411765, 0.4392156862745098, 0.9254901960784314, 1.0, 1.0, 1.0, 1.0, 0.9647058823529412, 0.7607843137254902, 0.5058823529411764, 0.27058823529411763, 0.08235294117647059, 0.0196078431372549, 0.00392156862745098, 0.0, 0.0, 0.0, 0.0, 0.17647058823529413, 0.792156862745098, 0.7568627450980392, 0.33725490196078434, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.00784313725490196, 0.17647058823529413, 0.596078431372549, 0.9568627450980393, 1.0, 1.0, 1.0, 1.0, 1.0, 0.984313725490196, 0.8549019607843137, 0.6392156862745098, 0.32941176470588235, 0.10196078431372549, 0.047058823529411764, 0.011764705882352941, 0.01568627450980392, 0.2901960784313726, 1.0, 1.0, 0.8941176470588236, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0196078431372549, 0.16862745098039217, 0.5764705882352941, 0.9450980392156862, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.996078431372549, 0.9215686274509803, 0.792156862745098, 0.6196078431372549, 0.6470588235294118, 0.7529411764705882, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.01568627450980392, 0.18823529411764706, 0.3411764705882353, 0.596078431372549, 0.8745098039215686, 0.9647058823529412, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.01568627450980392, 0.09803921568627451, 0.21176470588235294, 0.5294117647058824, 0.8588235294117647, 0.9764705882352941, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.00784313725490196, 0.08627450980392157, 0.22745098039215686, 0.5019607843137255, 0.796078431372549, 0.8588235294117647, 0.996078431372549, 1.0, 1.0, 1.0, 0.9372549019607843, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  data_t_fractional softmax_out[CLASSES_OUT] = {0,0,0,0,0,0,0,0,0,0};

	int prediction[100];
  struct timespec ts1, ts2;
  unsigned int time100= 0;
	for(int j=0; j<100; j++){
		timespec_get(&ts1, TIME_UTC);
	  dev_digits_classify(testimages[j], softmax_out);
		timespec_get(&ts2, TIME_UTC);
		time100 += tsdelta(&ts1, &ts2);
		data_t_fractional max = 0;
		for(int i = 0; i < CLASSES_OUT; i++) {
	    if (softmax_out[i] > max){
				max = softmax_out[i];
				prediction[j] = i;
			}

	  }
	}

  std::cout << "[INFO] SW Time taken to classify 100 image(s) is " << time100 <<" ns" << std::endl;

	int count = 0;
	for(int j=0; j<100; j++){
  	// std::cout <<"Number "<< prediction[j] <<std::endl;
		if (prediction[j] == truth100[j]) count++;
	}
	std::cout <<"[Info] Accuracy is "<< count <<"%"<<std::endl;

  return 0;
}