#pragma once

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxGui.h"
#include "animation_1.hpp"
#include "animation_2.hpp"
#include "animation_3.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		
        void animPlay(float time,int sequence);
        void Animation(int num);
        void Animation_setup(int num);
        int animSequence[3];
        int sumSequence;
        float animTime;
        int time;
        int count;
        Animation_1 anim1;
        Animation_2 anim2;
        Animation_3 anim3;
        float startTime;
        float endTime;
    
    ofShader blur, bloom;
    ofFbo fbo, onePassFbo, twoPassFbo;
    ofCamera cam;
    
    ofxPanel gui;
    ofParameter<float> strength;
    ofParameter<float> camx;
    ofParameter<float> camy;
    ofParameter<float> camz;
};
