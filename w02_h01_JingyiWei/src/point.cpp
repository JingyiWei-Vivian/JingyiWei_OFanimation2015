//
//  point.cpp
//  w02_h01_JingyiWei
//
//  Created by Vivian Wei 13" on 2/10/15.
//
//

#include "point.h"

point::point(){
    
}

void point::setup() {
    
    //initial position
    axPos = ofRandom(0, ofGetWindowWidth());
    ayPos = ofRandom(0, ofGetWindowHeight());
    bxPos = ofRandom(0, ofGetWindowWidth());
    byPos = ofRandom(0, ofGetWindowHeight());
}

void point::update() {
    
    //movement
    axPos ++;
    bxPos ++;
    
    
}

void point::draw() {
    
    //draw Points
    ofCircle(axPos, ayPos, 10);
    string infoA = "PointA";
    ofSetColor(0,0,0);
    ofDrawBitmapString(infoA, axPos+15, ayPos+15);
    
    ofCircle(bxPos, byPos, 20);
    string infoB = "PointB";
    ofSetColor(0,0,0);
    ofDrawBitmapString(infoB, bxPos+25, byPos+25);
    
    //draw a line between the two points
    ofLine(axPos, ayPos, bxPos, byPos);
}