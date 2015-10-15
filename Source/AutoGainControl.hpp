//
//  AutoGainControl.hpp
//  VolumeLeveler
//
//  Created by XinquanZhou on 10/14/15.
//
//

#ifndef AutoGainControl_hpp
#define AutoGainControl_hpp

#include <stdio.h>
#include "RMS.hpp"
#include "PeakMeter.hpp"
#include "StaticCurve.hpp"
#include <string>

enum PARAMS {TA, TR, TARGET, SLOPE};

class ACG{
private:
    RMS * rms;
    PeakMeter * peakmeter;
    StaticCurve * staticCurve;
    float fs;
    int blocksize;
    float * RMSBuffer = nullptr;
public:
    ACG(float target, float slope, float ta, float tr){
        rms = new RMS(tr/2);
        peakmeter = new PeakMeter(ta, tr);
        staticCurve = new StaticCurve(target, slope, ta, tr);
    }
    ~ACG(){
        delete rms;
        delete peakmeter;
        delete staticCurve;
        delete [] RMSBuffer;
        RMSBuffer = 0;
        rms = 0;
        peakmeter = 0 ;
        staticCurve = 0;
    }
    
    void init(float fs, int blocksize);
    void setParams(float val, int type);
    
    void process(float * input, float * output);
};
#endif /* AutoGainControl_hpp */
