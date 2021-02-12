//
//  animation_1.hpp
//  teamlab_kadai
//
//  Created by 角　伊織 on 2021/02/03.
//

#ifndef animation_1_hpp
#define animation_1_hpp

#include <stdio.h>
#include "ofMain.h"

class Animation_1{
    public :
        void setup();
        void update();
        void draw();
    
    int streetlamp_num;
    float streetlamp_z[100];
    float streetlamp_x,streetlamp_y;
    
    int traffic_num;
    float traffic_x[100],traffic_y[100];
    float traffic_z[100];
    ofParameter<float> z;
    
    int star_num;
    float star_x[100],star_y[100];
    float star_z;
    
    float vz;
};
#endif /* animation_1_hpp */
