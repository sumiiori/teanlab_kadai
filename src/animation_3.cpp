//
//  animation_3.cpp
//  teamlab_kadai
//
//  Created by 角　伊織 on 2021/02/03.
//

#include "animation_3.hpp"
void Animation_3::setup(){
    //雪
    for(int i = 0; i < 80; i++){
        snow_x[i] = ofRandom(-300, 300);
        snow_y[i] = ofRandom(-300, 300);
        snow_z[i] = ofRandom(100, -400);
    }
    
    //電車
    for(int j = 0; j < 20; j++){
        train_x[j] = j * 40;
        train_y[j] = 20;
        train_z[j] = j * 20 - 400;
    }

}

void Animation_3::update(){
    //雪
    for(int i = 0; i < 80; i++){
        snow_x[i] -= 0.1;
        snow_y[i] -= 0.2;
    }
    
    //電車
    for(int j = 0; j < 20; j++){
        train_x[j] -= 4;
        train_z[j] -= 1;

    }
    
}

void Animation_3::draw(){
    
    
    //電車
    ofSetColor(255, 180, 50);
    for(int j = 0; j < 20; j++){
        ofDrawCircle(train_x[j], train_y[j], train_z[j], 10);
    }
    //雪
    ofSetColor(200, 255, 255, 255);
    for(int i = 0; i < 80; i++){
        ofDrawCircle(snow_x[i], snow_y[i], snow_z[i], 3);
    }
}
