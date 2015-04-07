//
//  flowField.cpp
//  w07_h01_FlowField
//
//  Created by Vivian Wei 13" on 4/6/15.
//
//

#include "flowField.h"

flowField::flowField(){
    
}

void flowField::setup(float w, float h, float res){
    
    screenWidth = w;
    screenHeight = h;
    resolution = res;
    
    fieldWidth = ceil (screenWidth / resolution);
    fieldHeight = ceil (screenHeight / resolution);
    
    totalFlows = fieldWidth * fieldHeight;
    
    for (int i=0; i<totalFlows; i++){
        ofVec2f flow;
        flow.set(0.0, 0.0);
        field.push_back(flow);
    }
}

void flowField::setRandom(float scale){
    
    for (int i=0; i<totalFlows; i++){
        float x = ofRandom(-1, 1) * scale;
        float y = ofRandom(-1, 1) * scale;
        field[i].set(x, y);
    }
}

void flowField::setNoise(float dx, float dy){
    
    for (int y=0; y<fieldHeight; y++){
        for (int x=0; x<fieldWidth; x++){
            
            int index = (y * fieldWidth) + x;
            
                float noise = ofNoise (x*0.1, y*0.1);
                noise = ofMap(noise, 0, 1, 0, TWO_PI);

                field[index].set(ofVec2f(cos(noise) * dx, sin(noise) * dy));
            
        }
    }
}

void flowField::draw(){
    
    for (int y=0; y<fieldHeight; y++){
        for (int x=0; x<fieldWidth; x++){
            
            int index = (y * fieldWidth) + x;
            
            float x0 = x * resolution;
            float y0 = y * resolution;
            
            float x1 = x0 + (field[index].x * 5);
            float y1 = y0 + (field[index].y * 5);
            
            ofLine(x0, y0, x1, y1);
            
            ofCircle(x0, y0, 2);
        }
    }
}

ofVec2f flowField::getForceAt(float x, float y){
    
    ofVec2f frc;
    frc.set(0,0);
    
    if(x<0||x>screenWidth || y<0||y>screenHeight){
        return frc;
    }
    
    int xIndex = ceil(ofMap(x, 0, ofGetWidth(), 0, fieldWidth));
    int yIndex = ceil(ofMap(y, 0, ofGetHeight(), 0, fieldHeight));
    
    int index = (yIndex * fieldWidth) + xIndex;
    
    frc.set(field[index].x * 0.01, field[index].y * 0.01);
    
    return frc;
}


