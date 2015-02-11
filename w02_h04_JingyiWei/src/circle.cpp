//
//  circle.cpp
//  w02_h04_JingyiWei
//
//  Created by Vivian Wei 13" on 2/11/15.
//
//

#include "circle.h"

circle::circle(){
    
}

void circle::setup() {
    
}

void circle::update(float mPosx, float mPosy) {
    
    //update position
    pos.x = pos.x * (1-pct) + mPosx * pct;
    pos.y = pos.y * (1-pct) + mPosy * pct;
}

void circle::draw() {
    
    //set color and draw circle
    //each circle will have random alpha value so they could be seen as different object
    ofSetColor(255,255,255, ofRandom(100,255));
    ofCircle(pos.x, pos.y, rad);
}