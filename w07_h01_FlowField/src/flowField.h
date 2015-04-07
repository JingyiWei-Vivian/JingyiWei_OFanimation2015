//
//  flowField.h
//  w07_h01_FlowField
//
//  Created by Vivian Wei 13" on 4/6/15.
//
//

#pragma once
#include "ofMain.h"

class flowField{
public:
    
    flowField();
    
    void setup(float w, float h, float res);
    
    void setRandom(float scale);
    void setNoise(float dx, float dy);
    
    ofVec2f getForceAt(float x, float y);
    
    void draw();
    
    vector<ofVec2f> field;
    
    int screenWidth;
    int screenHeight;
    
    int fieldWidth;
    int fieldHeight;
    
    float resolution;
    
    int totalFlows;

};
