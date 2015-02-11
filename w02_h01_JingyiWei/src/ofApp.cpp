#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    
    myPoint.setup();
    
    //use bool to change either PointA or PointB
    mouseClick = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    myPoint.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //draw Points
    myPoint.draw();
    
    string info = "Click to change the position of PointA and PointB";
    ofSetColor(255,255,255);
    ofDrawBitmapString(info, 30, 30);
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
    
    //use bool to change either PointA or PointB
    if (mouseClick == true) {
        
        myPoint.axPos = mouseX;
        myPoint.ayPos = mouseY;
        mouseClick = false;
        
    } else {
        
        myPoint.bxPos = mouseX;
        myPoint.byPos = mouseY;
        mouseClick = true;
    }
    
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
