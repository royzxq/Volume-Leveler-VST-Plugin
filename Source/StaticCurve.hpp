//
//  StaticCurve.hpp
//  VolumeLeveler
//
//  Created by XinquanZhou on 10/14/15.
//
//

#ifndef StaticCurve_hpp
#define StaticCurve_hpp

#include <stdio.h>
#include <math.h>
#include "PeakMeter.hpp"
class StaticCurve: public SmoothingBase{
private:
    float target;
    float LT, CT, ET, NT, S;
    float diff = 0.06;
    float t;
public:
    StaticCurve(float target, float slope, float ta, float tr):SmoothingBase(ta,tr){
        this -> target = target;
        S = slope;
        LT = 2 * target > 0.99 ? 0.99 : 2 * target;
        CT = target + diff/2;
        ET = target - diff/2;
        NT = 0.03;
        LT = log2f(LT);
        CT = log2f(CT);
        ET = log2f(ET);
        NT = log2f(NT);
    }
    
    void setTarget(float target);
    void setSlope(float slope);
    
    void process(float * Peak, float * RMS, float * gain, int blocksize);
};
#endif /* StaticCurve_hpp */
