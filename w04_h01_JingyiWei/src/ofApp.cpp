#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //set background and circle resolution
    ofBackground(0);
    ofSetCircleResolution(200);
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i<50; i++){
        
        //rotating radius increse
        float rad = 20 + i*10;
        //angle, also used in sin&cos function
        float angle = (ofGetElapsedTimef()/10) * (i++);
        //circle position (rotation)
        float posX = ofGetWindowWidth()/2 + rad * sin(angle+(i++));
        float posY = ofGetWindowHeight()/2 + rad * cos(angle+(i++));
        
        //set color and circle position
        ofSetColor(posX, posY, ofRandom(255));
        ofCircle(posX, posY, i++/2);
        
        //draw line between the center point and circles
        ofSetColor(255);
        ofLine(posX, posY, ofGetWindowWidth()/2, ofGetWindowHeight()/2);
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
