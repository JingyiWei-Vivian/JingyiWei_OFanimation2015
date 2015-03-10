#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofBackground(0);
    gravity.set(0, ofRandom(0.08, 0.1));
    pos.x = ofGetWidth()/2;
    pos.y = ofGetHeight()/2;
    
    for (int i=0; i<500; i++){
        
        particle myParticle;
        
        float angle = ofRandom(0, 2*PI);
        float rad = ofRandom(0.05, 20.0);
        float vx = rad*cos(angle);
        float vy = rad*sin(angle);
        
        myParticle.setup(pos.x, pos.y, vx, vy);
        particleList.push_back(myParticle);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
        
        for (int i=0; i<particleList.size(); i++){
            
            particleList[i].resetForce();
            particleList[i].applyForce(gravity);
            particleList[i].applyDampingForce(damping);
            particleList[i].update();
        }

}
//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0; i<particleList.size(); i++){
        
        particleList[i].draw();
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
