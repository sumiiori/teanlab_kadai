//
//  animation_2.hpp
//  teamlab_kadai
//
//  Created by 角　伊織 on 2021/02/03.
//

#ifndef animation_2_hpp
#define animation_2_hpp

#include <stdio.h>
#include "ofMain.h"

class Animation_2{
    public:
        void setup();
        void update();
        void draw();
    
    float vz;
    float tunnel_z[49];
    float tunnel_x,tunnel_y;
    
    float car_x;
    float car_y;
    float car_z;
};
#endif /* animation_2_hpp */
