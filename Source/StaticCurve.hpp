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

class StaticCurve{
private:
    float target, ta, tr;
    float LT, CT, ET, NT, S;
    float diff = 0.06;
    float fs, ts, at, rt;
    float preGain = 1, t;
public:
    StaticCurve(float target, float slope, float ta, float tr){
        this -> target = target;
        this -> ta = ta;
        this -> tr = tr;
        
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
    
    void setFs(float fs);
    void setTa(float ta);
    void setTr(float tr);
    void setTarget(float target);
    void setSlope(float slope);
    
    void process(float * Peak, float * RMS, float * gain, int blocksize);
};
#endif /* StaticCurve_hpp */
