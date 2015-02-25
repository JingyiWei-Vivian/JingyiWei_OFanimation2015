//
//  tail.h
//  w04_h03_JingyiWei
//
//  Created by Vivian Wei 13" on 2/23/15.
//
//

#pragma once
#include "ofMain.h"

class tail {
public:
    
    void setup();
    void update(ofVec2f _dest);
    void draw(float _alpha, float _size);
    
    
    ofVec2f pos;
    float rad;
};