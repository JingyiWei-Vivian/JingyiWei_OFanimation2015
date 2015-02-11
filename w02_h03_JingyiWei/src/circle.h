//
//  circle.h
//  w02_h03_JingyiWei
//
//  Created by Vivian Wei 13" on 2/10/15.
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
};
