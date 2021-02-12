//
//  animation_3.hpp
//  teamlab_kadai
//
//  Created by 角　伊織 on 2021/02/03.
//

#ifndef animation_3_hpp
#define animation_3_hpp

#include <stdio.h>
#include "ofMain.h"

class Animation_3{
    public:
        void setup();
        void update();
        void draw();
    
    
    float train_x[20], train_y[20], train_z[20];
    float snow_x[80], snow_y[80], snow_z[80];
    
};
#endif /* animation_3_hpp */
