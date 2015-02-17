#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(100);
    ofEnableAlphaBlending();
    //ofSetBackgroundAuto(false);
    
    thisObject.setup();
    
    for (int i=0; i<1001; i++){
        
        object o;
        o.setup();
        objectList.push_back(o);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    float num = ofxGaussian();
//    float sd = 100;
//    float mean = ofGetWindowWidth()/2;
//    
//    x = (sd * num) + mean;
    
    thisObject.update();
    
    for (int i=0; i<1001; i++){
        
        objectList[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float num = ofxGaussian();
    float sd = 100;
    float mean = ofGetWindowWidth()/2;
    
    x = (sd * num) + mean;
    
    thisObject.draw(x, ofGetHeight());
    
    for (int i=0; i<1001; i++){
        
        objectList[i].draw(x, ofGetHeight());
    }
}

bool haveNextNextGaussian = false;
float nextNextGaussian;


float ofApp::ofxGaussian() {
    if (haveNextNextGaussian){
        haveNextNextGaussian = false;
        return nextNextGaussian;
    }
    else {
        float v1, v2, s;
        do {
            v1 = 2 * ofRandomf() - 1;
            v2 = 2 * ofRandomf() - 1;
            s = v1 * v1 + v2 * v2;
        }
        while (s >= 1 || s == 0);
        
        float multiplier = sqrt(-2 * log(s)/s);
        nextNextGaussian = v2 * multiplier;
        haveNextNextGaussian = true;
        
        return v1 * multiplier;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
