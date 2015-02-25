//
//  Circle.h
//  w02_h02_JingyiWei
//
//  Created by Vivian Wei 13" on 2/10/15.
//
//

#pragma once
#include "ofMain.h"

class Circle {
public:
    Circle();
    void setup(ofVec2f _initPos, ofVec2f _finPos, float _initR, float _finR);
    void update(float _pct, float _rad);
    void draw();
    
    ofVec2f initPos, currentPos, finPos;
    float initR, currentR, finR;
    float pct;
    float rad;
    
};