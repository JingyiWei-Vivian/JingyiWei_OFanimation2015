#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //prepare the canvas
    ofBackground(255);
    ofSetBackgroundAuto(false);
    ofSetVerticalSync(true);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    myTool.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

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
    
    myTool.start.x = mouseX;
    myTool.start.y = mouseY;
    myTool.finish.x = myTool.start.x;
    myTool.finish.y = myTool.start.y;
    myTool.draw();
    
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
