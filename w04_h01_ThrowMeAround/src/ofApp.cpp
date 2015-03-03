#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //setup the ball
    ofBackground(0);
    myBall.setup(ofGetMouseX(), ofGetMouseY(), 1.0);
    gravity.set(0, 0.5);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //update
    myBall.resetForces();
    myBall.applyForce(gravity*myBall.mass);
    myBall.applyDampingForce(0.01*myBall.mass);
    myBall.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //draw the ball
    ofSetColor(255);
    myBall.draw();
    
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
    
    //apply throwing force, and use that as vel
    myBall.vel.x = ofGetMouseX() - ofGetPreviousMouseX();
    myBall.vel.y = ofGetMouseY() - ofGetPreviousMouseY();

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    //check if the ball is thrown, and set the pos
    if (thrown) {
        posX = ofGetMouseX();
        posY = ofGetMouseY();
        thrown = false;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    //check if the ball is thrown, and set the pos
    myBall.pos.set(ofGetMouseX(), ofGetMouseY());
    thrown = true;
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
