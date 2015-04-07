#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    
    flowField.setup(ofGetWidth(), ofGetHeight(), 20.0);
    flowField.setNoise(0.1, 0.1);
    
    for (int i=0; i<5000; i++){
        Particle myParticle;
        myParticle.setup();
        particles.push_back(myParticle);
    }
    
    bDrawField = false;
    bDrawBackground = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<particles.size(); i++){
        particles[i].resetForces();
        
        ofVec2f frc = flowField.getForceAt(particles[i].pos.x, particles[i].pos.y);
        
        particles[i].applyForce(frc);
        particles[i].applyDampingForce(0.01);
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(bDrawBackground == true) {
        ofBackground(255);
    }
    if(bDrawField == true){
        flowField.draw();
    }

    for (int i=0; i<particles.size(); i++){
        
        ofSetColor(145, 126, 196, 100);
        particles[i].draw();
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
        case 'f' | 'F':
            bDrawField = !bDrawField;
            break;
        case 'b' | 'B' :
            bDrawBackground = !bDrawBackground;
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    ofVec2f diff;
    
    diff.x = x - pmouseX;
    diff.y = y - pmouseY;
    
    flowField.setNoise(diff.x*0.3, diff.y*0.3);
    
    pmouseX = x;
    pmouseY = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    pmouseX = x;
    pmouseY = y;
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
