//
//  tail.h
//  w05_h01_Fireworks
//
//  Created by Vivian Wei 13" on 3/6/15.
//
//

#pragma once
#include "ofMain.h"

class tail {
public:
    
    void setup();
    void update(float xPos, float yPos);
    void draw();
    
    ofPoint myPoint;
    vector<ofPoint> points;
};