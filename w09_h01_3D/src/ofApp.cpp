#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    myField.setup(1000, 1000, 1000, 100);
    myField.setNoise();
    
    particleList.clear();
    
    for( int i=0; i<1000; i++ ){
        Particle part;
        part.pos = ofVec3f( ofRandom(myField.width), ofRandom(myField.height), ofRandom(myField.depth) );
        
        particleList.push_back( part );
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for( int i=0; i<particleList.size(); i++ ){
        particleList[i].resetForce();
        particleList[i].applyForce( myField.getForceAtPosition(particleList[i].pos ) * 0.005 );
        particleList[i].applyDampingForce(0.2);
        particleList[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofColor centerCol = ofColor(85, 78, 68);
    ofColor edgeCol (0, 0, 0);
    ofBackgroundGradient (centerCol, edgeCol, OF_GRADIENT_CIRCULAR);
    
    myCam.begin();
    
    ofPushMatrix(); {
        ofTranslate(myField.width*0.2*-1, myField.height*0.2*-1, myField.depth*0.2*-1);

        for( int i=0; i<particleList.size(); i++ ){
            particleList[i].draw();
        }
        
    }
    
    //myField.draw();
    ofPopMatrix();
    myCam.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (int key = 'f'){
        myField.draw();
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
