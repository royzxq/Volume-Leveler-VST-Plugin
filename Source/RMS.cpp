//
//  RMS.cpp
//  VolumeLeveler
//
//  Created by XinquanZhou on 10/14/15.
//
//

#include "RMS.hpp"

void RMS::setFs(float fs){
    this -> fs = fs;
    tav = 1 - exp2f(-2.2 / fs / (tm/1000));
}

void RMS::setTm(float tm){
    this -> tm = tm;
    tav = 1 - exp2f(-2.2 / fs / (tm/1000));
}

void RMS::process(const float *input, float *output, int blocksize){
    for (int i = 0 ; i < blocksize; i++) {
        output[i] = sqrtf((1-tav) * preRMS * preRMS + tav * input[i] * input[i]);
        preRMS = output[i];
        output[i] = log2f(output[i]) * 0.5;
    }
}