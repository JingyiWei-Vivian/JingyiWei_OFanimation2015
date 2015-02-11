#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    
    ofBackground(0);
    
    //circle array
    for (int i=0; i<10; i++) {
        
        myCircle[i].setup();
        myCircle[i].pct = 0.001*i*4;
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //update position to follow the mouse
    for (int i=0; i<10; i++) {
        
        myCircle[i].update(mouseX, mouseY);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //draw circles
    for (int i=0; i<10; i++) {
        
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
