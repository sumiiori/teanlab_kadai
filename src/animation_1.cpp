//
//  animation_1.cpp
//  teamlab_kadai
//
//  Created by 角　伊織 on 2021/02/03.
//

#include "animation_1.hpp"
void Animation_1::setup(){
    //速度
    vz = 3.0;
    //星の数
    star_num = 100 - (streetlamp_num * 2) - traffic_num;
    //外灯
    for(int i = 0; i < streetlamp_num; i++){
        streetlamp_z[i] = -1900 + i * (2000/streetlamp_num);
        streetlamp_x = 200;
        streetlamp_y = 100;
    }
    //信号
    for(int j = 0; j < traffic_num; j++){
        traffic_y[j] = 40;
        if(j % 2 == 0){
            traffic_x[j] = -90;
            traffic_z[j] = -1700 + j * (2000/traffic_num);
        }else{
            traffic_x[j] = 90;
            traffic_z[j] = -1900 + (j-1) * (2000/traffic_num);
        }
    }
    //星
    for(int k = 0; k < star_num; k++){
        star_x[k] = ofRandom(-3000, 8000);
        star_y[k] = ofRandom(0, 3000);
    }
    star_z = -5000;
}
//----------------------------------------------
void Animation_1::update(){
    //外灯
    for(int i = 0; i < streetlamp_num; i++){
        streetlamp_z[i] += vz;
        if(streetlamp_z[i] > 100){
            streetlamp_z[i] = -1900;
        }
    }
    //信号
    for(int j = 0; j < traffic_num; j++){
        traffic_z[j] += vz;
        if(traffic_z[j] > 100){
            traffic_z[j] = -1900;
        }
    }
}
//-----------------------------------------------
void Animation_1::draw(){
    //外灯
    ofSetColor(255, 255, 255, 255);
    for(int i = 0; i< streetlamp_num; i++){
        ofDrawCircle(streetlamp_x, streetlamp_y, streetlamp_z[i], 10);
        ofDrawCircle(streetlamp_x*-1, streetlamp_y, streetlamp_z[i], 10);
    }
    //信号
    ofSetColor(0, 255, 100, 255);
    for(int j = 0; j < traffic_num; j++){
        if(j % 2 == 0){
            ofDrawCircle(traffic_x[j], traffic_y[j], traffic_z[j], 8);

        }else{
            ofDrawCircle(traffic_x[j], traffic_y[j], traffic_z[j], 8);
        }
    }
    //星
    ofSetColor(255, 255, 100, 255 * star_num/100);
    for(int k = 0; k < star_num; k++){
        ofDrawCircle(star_x[k], star_y[k], star_z, 5);
    }
   // ofDrawCircle(0, z, -5000, 10);
//    ofDrawCircle(-200, 100, z, 10);
    
}
