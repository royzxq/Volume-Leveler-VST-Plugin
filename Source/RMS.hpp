//
//  RMS.hpp
//  VolumeLeveler
//
//  Created by XinquanZhou on 10/14/15.
//
//

#ifndef RMS_hpp
#define RMS_hpp

#include <stdio.h>
#include <math.h>

class RMS{
private:
    float tm;
    float fs, tav;
    float preRMS = 1;
public:
    RMS(float tm){
        this -> tm = tm;
    }
    void setFs(float fs);
    void setTm(float tm);
    void process(float * input, float * output, int blocksize);
};
#endif /* RMS_hpp */
