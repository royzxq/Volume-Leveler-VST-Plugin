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

class PeakMeter {
private:
    float ta, tr;
    float fs, ts, at, rt;
    float prePeak = 1.0;
public:
    PeakMeter(float ta, float tr){
        this->ta = ta;
        this->tr = tr;
    }
    void setFs(float fs);
    void setTa(float ta);
    void setTr(float tr);
    void process(float * input, float *output, int blocksize);
    
};
#endif /* PeakMeter_hpp */
