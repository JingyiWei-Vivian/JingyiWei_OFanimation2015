#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofBackground(0);
    
    for (int i=0; i<20; i++) {
        
        
        myCircle[i].pos.x = ofGetWindowWidth()/2;
        myCircle[i].pos.y = ofGetWindowHeight()/2;
        myCircle[i].rad = i*2;
        myCircle[i].pct = 0.05f;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //first circle follows the mouse, and the second follows the first, etc.
    myCircle[0].update(mouseX, mouseY);
    
    for (int i=1; i<20; i++) {
        myCircle[i].update(myCircle[i-1].pos.x, myCircle[i-1].pos.y);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0; i<20; i++) {
        
        myCircle[i].draw();
    }
    
    ofSetColor(255,255,255);
    ofDrawBitmapString("Move your mouse around to see the action", 50, 50);
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
