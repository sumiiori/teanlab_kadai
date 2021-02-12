//
//  animation_2.cpp
//  teamlab_kadai
//
//  Created by 角　伊織 on 2021/02/03.
//

#include "animation_2.hpp"
void Animation_2::setup(){
    for(int i = 0; i < 49; i++){
        tunnel_z[i] = -2500 + i * (2600 / 49);
    }
    tunnel_x = 200;
    tunnel_y = 100;

    car_x = 100;
    car_y = 0;
    car_z = -1500;
    vz = 5;
}

void Animation_2::update(){
    for(int i = 0; i < 49; i++){
        tunnel_z[i] += vz;
        car_z += 0.3;
        if(tunnel_z[i] > 100){
            tunnel_z[i] = -2500;
        }
    }
}

void Animation_2::draw(){
    ofSetColor(255, 50, 10, 255);
    for(int i = 0; i < 49; i++){
        ofDrawCircle(tunnel_x, tunnel_y, tunnel_z[i], 10);
        ofDrawCircle(tunnel_x*-1, tunnel_y, tunnel_z[i], 10);
    }
    ofSetColor(255, 180, 50);
    ofDrawCircle(car_x, car_y, car_z, 5);
    ofDrawCircle(car_x -50, car_y, car_z, 5);
    
    
}
