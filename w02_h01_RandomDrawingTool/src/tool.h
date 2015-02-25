//
//  tool.h
//  w03_h01_JingyiWei
//
//  Created by Vivian Wei 13" on 2/12/15.
//
//

#pragma once
#include "ofMain.h"

class tool {
public:
    
    void setup();
    void update();
    void draw();
    
    ofPoint start;
    ofPoint finish;
    int rad;

};