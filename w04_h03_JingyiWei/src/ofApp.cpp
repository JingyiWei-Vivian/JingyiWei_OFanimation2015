#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetVerticalSync(true);
    yOffset = 100.0;
    
    //initial addon
    rip.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    
    //array for the tail, size increase
    for (int i=0; i<20; i++){
        
        tail myTail;
        myTail.setup();
        tailList.push_back(myTail);
        
        myTail.rad = ofMap(sin(ofGetElapsedTimef()), -1, 1, i/2, i*2);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    //setup movement
    float noiseX = ofNoise(ofGetElapsedTimef()/10);
    float noiseY = ofNoise(ofGetElapsedTimef()/10+yOffset);
    pos.x = ofMap(noiseX, 0, 1, 0, ofGetWidth());
    pos.y = ofMap(noiseY, 0, 1, 0, ofGetHeight());
    
    tailList[0].update(pos);
    
    //update array list, mapping sin to size and alpha
    for (int i=1; i<tailList.size(); i++){
        
        tailList[i].update(tailList[i-1].pos);
        
        float sinOfTime = sin(ofGetElapsedTimef());
        size = ofMap(sinOfTime, -1, 1,(i*2)*0.5, (i/2)*0.3);
        alpha = ofMap(sinOfTime, -1, 1, 10, 250);
        
        }
    
    //setup addon
    rip.begin();
    ofFill();
    ofSetColor(ofNoise(ofGetFrameNum()*0.001) * 255 * 5, 150);
    ofCircle(pos, 10);
    rip.end();
    rip.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //using addon
    ofBackground(255);
    ofSetColor(255,255);
    rip.draw(ofRandom(0,1), ofRandom(0,1));
    
    for (int i=1; i<tailList.size(); i++){
        tailList[i].draw(alpha, size);
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
