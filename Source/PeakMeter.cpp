//
//  PeakMeter.cpp
//  VolumeLeveler
//
//  Created by XinquanZhou on 10/14/15.
//
//

#include "PeakMeter.hpp"


void PeakMeter::setFs(float fs){
    this -> fs = fs;
    ts = 1.0 / fs;
    at = 1 - exp2f(-2.2 * ts/ta * 1000);
    rt = 1 - exp2f(-2.2 * ts/tr * 1000);
}

void PeakMeter::setTa(float ta){
    this -> ta = ta;
    at = 1 - exp2f(-2.2 * ts/ta * 1000);
}

void PeakMeter::setTr(float tr){
    this -> tr = tr;
    rt = 1 - exp2f(-2.2 * ts/tr * 1000);
}
void PeakMeter::process(float *input, float *output, int blocksize){
    for (int i = 0 ; i < blocksize; i++) {
        if (fabsf(input[i]) > fabsf(prePeak)) {
            output[i] = (1-at) * prePeak + at * (fabsf(input[i]));
        }
        else{
            output[i] = (1-rt) * prePeak;
        }
        prePeak = output[i];
        output[i] = log2f(output[i]);
    }
}