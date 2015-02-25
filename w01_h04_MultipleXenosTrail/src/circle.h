//
//  circle.h
//  w02_h04_JingyiWei
//
//  Created by Vivian Wei 13" on 2/11/15.
//
//

#pragma once
#include "ofMain.h"

class circle {
public:
    circle();
    void setup();
    void update(float mPosx, float mPosy);
    void draw();
    
    //use ofPoint for positionX and positionY
    ofPoint pos;
    float pct;
    float rad;
};
