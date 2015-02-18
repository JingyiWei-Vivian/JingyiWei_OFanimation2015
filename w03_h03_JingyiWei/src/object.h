//
//  object.h
//  w03_h03_JingyiWei
//
//  Created by Vivian Wei 13" on 2/17/15.
//
//

#pragma once
#include "ofMain.h"

class object{
public:
    
    void setup();
    void update(ofVec2f P);
    void draw();
    
    ofVec2f pos;
    
};


