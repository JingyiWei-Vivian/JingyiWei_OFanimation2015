#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //setup the canvas
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetCircleResolution(3);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //get the value of atan2
    newPos.set(mouseX, mouseY);
    pos.set(_x, _y);
    
    ofVec2f diff;
    diff = newPos - pos;
    
    rot = atan2(diff.y, diff.x);
    rot = ofRadToDeg(rot);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //draw the patterns, rot controls the size
    ofSeedRandom(10);

    float spacing = 20;
    for (int x = 0; x < ofGetWidth(); x = x+spacing){
        for (int y = 0; y < ofGetHeight(); y = y+spacing){
            
            
            ofSetColor(x, ofRandom(255), y, ofRandom(10, 100));
            ofCircle(x, y, rot);

        }
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
