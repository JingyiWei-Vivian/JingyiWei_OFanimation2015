//
//  Circle.cpp
//  w02_h02_JingyiWei
//
//  Created by Vivian Wei 13" on 2/10/15.
//
//

#include "Circle.h"

Circle::Circle() {
    
}

void Circle::setup(ofVec2f _initPos, ofVec2f _finPos, float _initR, float _finR){
    
    initPos = _initPos;
    finPos = _finPos;
    initR = _initR;
    finR = _finR;
    
}

void Circle::update(float _pct, float _rad) {
    
    rad = _rad;
    pct = _pct;
    currentPos = initPos * (1-pct) + finPos * pct;
    currentR = initR * (1-pct) + finR * pct;
}

void Circle::draw() {
    
    ofSetColor(174,198,233, ofRandom(10,200));
    ofCircle(currentPos, currentR);
    
}