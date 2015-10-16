//
//  StaticCurve.cpp
//  VolumeLeveler
//
//  Created by XinquanZhou on 10/14/15.
//
//

#include "StaticCurve.hpp"



void StaticCurve::setSlope(float slope){
    S = slope;
}

void StaticCurve::setTarget(float target){
    LT = 2 * target > 0.99 ? 0.99 : 2 * target;
    CT = target + diff/2;
    ET = target - diff/2;
    NT = 0.03;
    LT = log2f(LT);
    CT = log2f(CT);
    ET = log2f(ET);
    NT = log2f(NT);
}

void StaticCurve::process(float *Peak, float *RMS, float *gain, int blocksize){
    for (int i = 0 ; i < blocksize; i ++) {
        if (Peak[i] > LT) {
            gain[i] = -(Peak[i] - LT) * S - S*(LT - CT);
        }
        else if (RMS[i] > CT){
            gain[i] = -(RMS[i] - CT) * S * 0.75;
        }
        else if (RMS[i] < NT){
            gain[i] = -(RMS[i] - NT) * S - S * (ET-NT);
        }
        else if (RMS[i] < ET){
            gain[i] = (ET - RMS[i]) * S * 0.75;
        }
        else{
            gain[i] = 0 ;
        }
        gain[i] = powf(2.0, gain[i]);
        t = gain[i] > preVal ? at : rt ;
        gain[i] = (1-t) * preVal + t * gain[i];
        preVal = gain[i];
    }
}