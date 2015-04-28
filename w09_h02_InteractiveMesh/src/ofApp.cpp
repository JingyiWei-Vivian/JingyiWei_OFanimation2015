#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    soundStream.listDevices();
    int bufferSize = 256;
    volHistory.assign(400, 0.0);
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    bufferCounter = 0;
    smoothedVol = 0.0;
    scaledVol = 0.0;
    drawCounter = 0;
    soundStream.setup(this, 0, 2, 44100, bufferSize, 2);
    
    //mesh.setMode(OF_PRIMITIVE_LINE_LOOP);
    
    width = 50;
    height = 50;
    res = 10;
    
    watercolor.loadImage("watercolor.png");
    
    for (int y = -height/2; y < height/2; y++){
        for (int x = -width/2; x < width/2; x++){
            mesh.addVertex(ofVec3f(x*res,y*res,0));
        }
    }
    
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            mesh.addTexCoord(ofVec2f(x, height-y)*res);
        }
    }
    

    for (int y = 0; y<height-1; y++){
        for (int x=0; x<width-1; x++){
            mesh.addIndex(x+y*width);
            mesh.addIndex((x+1)+y*width);
            mesh.addIndex(x+(y+1)*width);
            
            mesh.addIndex((x+1)+y*width);
            mesh.addIndex((x+1)+(y+1)*width);
            mesh.addIndex(x+(y+1)*width);
            
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    volHistory.push_back(scaledVol);
    
    for (int y = 0; y < height; y++){
        for (int x = 0; x< width; x++){
    
            int index = (y * width) + x;
    
            ofVec3f pos = mesh.getVertex(index);
            pos.z = ofNoise((x+cos(scaledVol)), (y+sin(scaledVol))) * 100.0;
            mesh.setVertex(index, pos);
            
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    easyCam.begin();
    watercolor.bind();
    mesh.drawWireframe();
    watercolor.unbind();
    easyCam.end();
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    int numCounted = 0;
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    curVol /= (float)numCounted;
    curVol = sqrt( curVol );
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    bufferCounter++;
    
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
