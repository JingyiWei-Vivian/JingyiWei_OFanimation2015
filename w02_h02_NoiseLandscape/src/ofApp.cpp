#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(0);
    ofDrawBitmapString("move your mouse around!", 30, 30);
    
    ofSeedRandom(10);
    
    ofBeginShape();
    for (int i=0; i<mouseX*0.1; i++){
            
        float noiseX = ofNoise(ofGetElapsedTimef()*0.2, i*0.2)*ofGetWidth();
        float noiseY = ofNoise(ofGetElapsedTimef()*0.2, i*0.2)*ofGetHeight();
        
        pos1.x = ofMap(noiseX, 0, ofGetWidth(), 0, ofGetWidth());
        pos1.y = ofMap(noiseY, 0, ofGetHeight(), 0, ofGetHeight());
        
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255), ofRandom(0, 100));
        
        ofVertex(pos1.x, pos1.y);
        ofVertex(pos1.x+300, pos1.y+500);
        ofVertex(pos1.x+800, pos1.y+250);
        ofVertex(pos1.x-700, pos1.y-200);
        ofVertex(pos1.x, pos1.y);
    }
    ofEndShape();
    
    ofBeginShape();
    for (int j=0; j<mouseY*0.1; j++){
        float noiseX = ofNoise(ofGetElapsedTimef()*0.2, j*0.2)*ofGetWidth();
        float noiseY = ofNoise(ofGetElapsedTimef()*0.2, j*0.2)*ofGetHeight();
        
        pos2.x = ofMap(noiseX, 0, ofGetWidth(), 0, ofGetWidth());
        pos2.y = ofMap(noiseY, 0, ofGetHeight(), 0, ofGetHeight());
        
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255), ofRandom(0, 100));
        
        ofVertex(pos2.x, pos2.y);
        ofVertex(pos2.x+500, pos2.y+300);
        ofVertex(pos2.x+250, pos2.y+800);
        ofVertex(pos2.x-200, pos2.y-700);
        ofVertex(pos2.x, pos2.y);
 
    }
    ofEndShape();
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
