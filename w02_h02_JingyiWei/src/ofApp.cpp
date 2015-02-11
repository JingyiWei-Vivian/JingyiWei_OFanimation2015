#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    
    ofBackground(0);
    ofSetCircleResolution(100);
    
    pct = 0;
    rad = 10;
    
    for (int i=0; i<10; i++){
        myCircle[i].setup(ofVec2f (ofRandom(0, ofGetWindowWidth()),ofGetWindowHeight()), ofVec2f (ofRandom(0, ofGetWindowWidth()),100),10,100);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(pct < 1){
        
        pct += 0.002;
    }
    
    for (int i= 0; i<10; i++){
        myCircle[i].update(pct, rad);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i =0; i<10; i++){
        myCircle[i].draw();
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
