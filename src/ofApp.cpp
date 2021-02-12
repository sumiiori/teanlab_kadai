#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //xmlの読み込み
    ofxXmlSettings settings;
    if(settings.loadFile("settings.xml")){
        settings.pushTag("settings");
        sumSequence = settings.getNumTags("sequence");
        animTime = settings.getValue("time",5.0);
        anim1.streetlamp_num = settings.getValue("streetlamp",10);
        anim1.traffic_num = settings.getValue("traffic",4);
        for(int i = 0; i < sumSequence; i++){
            animSequence[i] = settings.getValue("sequence", 0, i);
        }
    }
    else{
        ofLogError("Position file did not load!");
    }
    
    //Timerの設定
    startTime = ofGetElapsedTimeMillis();
    endTime = animTime;
    
    time = 0;
    count = 0;

    
    ofBackground(0);
    ofSetVerticalSync(true);
    blur.load("shader/blur.vert", "shader/blur.frag");
    bloom.load("shader/bloom.vert", "shader/bloom.frag");
       
    fbo.allocate(ofGetWidth(), ofGetHeight());
    onePassFbo.allocate(ofGetWidth(), ofGetHeight());
    twoPassFbo.allocate(ofGetWidth(), ofGetHeight());
       
    gui.setup();
    gui.setPosition(10, 10);
    gui.add(camx.set("camx", 0, -200, 200));
    gui.add(camy.set("camy", 0, -200, 200));
    gui.add(camz.set("camz", 200, -200, 500));
    gui.add(anim1.z.set("z",-100,-3000,10000));
    gui.add(strength.set("strength", 1.5, 0, 10));
    
    //カメラ設定
    cam.lookAt(ofVec3f(0,0,0));
    Animation_setup(animSequence[0]);

    
}

//--------------------------------------------------------------
void ofApp::update(){
    time++;
    
    fbo.begin();
        
    ofClear(0, 0, 0, 0);
    cam.begin();
        
        
    ofSetColor(255, 255, 255, 255);
    Animation(animSequence[count % sumSequence]);
    
    cam.end();
        
    fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
    float timer = ofGetElapsedTimeMillis() - startTime;
    

    //timer
    if(timer >= endTime * 1000){
        count++;
        startTime = ofGetElapsedTimeMillis();
        
        //setup初期化
        Animation_setup(animSequence[count % sumSequence]);
    }
    
    onePassFbo.begin();

    blur.begin();

    blur.setUniformTexture("tex", fbo.getTexture(), 0);
    blur.setUniform1i("horizontal", true);
    blur.setUniform1f("strength", strength);
    fbo.draw(0, 0);

    blur.end();

    onePassFbo.end();
    
    twoPassFbo.begin();

    blur.begin();
    blur.setUniformTexture("tex", onePassFbo.getTexture(), 0);
    blur.setUniform1i("horizontal", false);
    blur.setUniform1f("strength", strength);

    onePassFbo.draw(0, 0);

    blur.end();

    twoPassFbo.end();
    
    bloom.begin();
    bloom.setUniformTexture("tex", fbo.getTexture(), 0);
    bloom.setUniformTexture("blur", twoPassFbo.getTexture(), 1);

    fbo.draw(0, 0);

    bloom.end();
    
    gui.draw();
    //ループ再生
    //fps表示
    ofSetColor(255, 255, 255, 255);
    ofDrawBitmapString(ofToString(ofGetFrameRate()) + "fps", 20, 100);
    ofDrawBitmapString(ofToString(time) + "time", 20, 120);
    ofDrawBitmapString(ofToString(count) + "count", 20, 140);
}

//--------------------------------------------------------------
void ofApp::animPlay(float time,int sequence){
    for(int i = 0; i < time*60; i++){
        Animation(sequence);
    }
}

//--------------------------------------------------------------
void ofApp::Animation(int num){
    if(num==0){
        anim1.update();
        anim1.draw();
    }
    if(num==1){
        anim2.update();
        anim2.draw();
    }
    if(num==2){
        cam.setPosition(camx, camy, camz);
        anim3.update();
        anim3.draw();
    }
}

void ofApp::Animation_setup(int num){
    if(num==0){
        anim1.setup();
        cam.lookAt(ofVec3f(0,0,0));
        cam.setPosition(-50, -10, 200);
    }
    if(num==1){
        anim2.setup();
        cam.setPosition(-20, -10, 200);
    }
    if(num==2){
        anim3.setup();
        cam.setPosition(camx, camy, camz);
    }
}
