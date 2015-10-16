//
//  PeakMeter.cpp
//  VolumeLeveler
//
//  Created by XinquanZhou on 10/14/15.
//
//

#include "PeakMeter.hpp"

void SmoothingBase::setFs(float fs){
    this -> fs = fs;
    ts = 1.0 / fs;
    at = 1 - exp2f(-2.2 * ts/ta * 1000);
    rt = 1 - exp2f(-2.2 * ts/tr * 1000);
}

void SmoothingBase::setTa(float ta){
    this -> ta = ta;
    at = 1 - exp2f(-2.2 * ts/ta * 1000);
}

void SmoothingBase::setTr(float tr){
    this -> tr = tr;
    rt = 1 - exp2f(-2.2 * ts/tr * 1000);
}


void PeakMeter::process(const float *input, float *output, int blocksize){
    for (int i = 0 ; i < blocksize; i++) {
        if (fabsf(input[i]) > fabsf(preVal)) {
            output[i] = (1-at) * preVal + at * (fabsf(input[i]));
        }
        else{
            output[i] = (1-rt) * preVal;
        }
        preVal = output[i];
        output[i] = log2f(output[i]);
    }
}