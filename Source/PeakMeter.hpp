//
//  PeakMeter.hpp
//  VolumeLeveler
//
//  Created by XinquanZhou on 10/14/15.
//
//

#ifndef PeakMeter_hpp
#define PeakMeter_hpp

#include <stdio.h>
#include <math.h>

class SmoothingBase {
protected:
    float ta, tr;
    float fs, ts, at, rt;
    float preVal = 1.0;
    
public:
    SmoothingBase(float ta, float tr){
        this -> ta = ta;
        this -> tr = tr;
    }
    void setFs(float fs);
    void setTa(float ta);
    void setTr(float tr);
};

class PeakMeter: public SmoothingBase {

public:
    PeakMeter(float ta, float tr):SmoothingBase(ta, tr){
    }
    
    void process(const float * input, float *output, int blocksize);
    
};
#endif /* PeakMeter_hpp */
