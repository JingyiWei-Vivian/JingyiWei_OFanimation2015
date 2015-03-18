#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofBackground(0);

    soundStream.listDevices();
    int bufferSize = 256;
    volHistory.assign(400, 0.0);
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    bufferCounter = 0;
    smoothedVol = 0.0;
    scaledVol = 0.0;
    drawCounter = 0;
    soundStream.setup(this, 0, 2, 44100, bufferSize, 2);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    volHistory.push_back(scaledVol);
    
    //regular update stuff
    for (int i=0; i<particleList.size(); i++){

// uncomment this for different effect
//        ofVec2f diff = particleList[i].pos - particleList[i-1].pos;
//        repulsion.set(diff.getNormalized()*(scaledVol*10.0f)*-1);
        
        particleList[i].resetForce();
        particleList[i].applyForce(force);
        //particleList[i].applyForce(repulsion);
        particleList[i].pct = 0.05f;
        particleList[i].update(particleList[i-1].pos);

    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //volume controls size, color and shape
    for (int i=0; i<particleList.size(); i++){
        
        if( scaledVol <= 0.2 && scaledVol > 0.0){
            
            color.set(50, 50, 255);
            ofSetCircleResolution(3);
            force.set(scaledVol*0.1);
        }
        
        if(scaledVol <= 0.4 && scaledVol > 0.2){
            
            color. set(150, 150, 255);
            ofSetCircleResolution(8);
            force.set(scaledVol*0.5);
        }
        
        if(scaledVol <= 0.6 && scaledVol > 0.4){
            
            color.set(200, 200, 255);
            ofSetCircleResolution(4);
            force.set(scaledVol*0.9);
        }
        
        if(scaledVol <= 1.0 && scaledVol > 0.6){
            
            color.set(237, 237, 255);
            ofSetCircleResolution(100);
            force.set(scaledVol*1.2);
        }
        
        particleList[i].draw(color);
        ofLine(particleList[i].pos, particleList[i-1].pos);
    }
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    int numCounted = 0;
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    curVol /= (float)numCounted;
    curVol = sqrt( curVol );
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    bufferCounter++;
    
    //draw particle
    float angle = ofRandom(0, 2*PI);
    float rad = ofRandom(scaledVol*50.0f, scaledVol*100.0f);
    float vx = rad*cos(angle);
    float vy = rad*sin(angle);
    Particle p(ofVec2f(ofGetWindowSize()/2), vx, vy);
    particleList.push_back(p);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //mute/start
    if( key == 's' ){
        soundStream.start();
    }
    
    if( key == 't' ){
        soundStream.stop();
    }
    
    if( key == 'd'){
        ofSetBackgroundAuto(false);
    }
    
    if( key == 'm'){
        ofSetBackgroundAuto(false);
        ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    }
    
    if( key == 'a'){
        ofSetBackgroundAuto(false);
        ofEnableBlendMode(OF_BLENDMODE_ADD);
    }
    
    if( key == 'r'){
        ofSetBackgroundAuto(true);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
