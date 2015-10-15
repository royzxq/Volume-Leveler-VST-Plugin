//
//  AutoGainControl.cpp
//  VolumeLeveler
//
//  Created by XinquanZhou on 10/14/15.
//
//

#include "AutoGainControl.hpp"

void ACG::init(float fs, int blocksize){
    this-> fs = fs;
    rms->setFs(fs);
    peakmeter->setFs(fs);
    staticCurve -> setFs(fs);
    this->blocksize = blocksize;
    RMSBuffer = new float[blocksize];
}

void ACG::setParams(float val, int type){
    switch (type) {
        case PARAMS::TA :
            peakmeter->setTa(val);
            staticCurve->setTa(val);
            break;
        case PARAMS::TR :
            rms -> setTm(val);
            peakmeter->setTr(val);
            staticCurve->setTr(val);
            break;
        case PARAMS::TARGET:
            staticCurve->setTarget(val);
            break;
        case PARAMS::SLOPE:
            staticCurve->setSlope(val);
            break;

        default:
            break;
    }
}

void ACG::process(float *input, float *output){
    peakmeter->process(input, output, blocksize);
    rms -> process(input, RMSBuffer, blocksize);
    staticCurve->process(output, RMSBuffer, output, blocksize);
    for (int i = 0 ; i < blocksize; i++) {
        output[i] = output[i] * input[i];
        if (fabs(output[i]) >= 1.0) {
            output[i] = 0.9999;
        }
    }
}