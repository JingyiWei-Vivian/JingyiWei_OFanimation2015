//
//  Particle.h
//  Midterm
//
//  Created by Vivian Wei 13" on 3/15/15.
//
//

#pragma once
#include "ofMain.h"

class Particle{
public:
    
    Particle(ofVec2f _pos, float vx, float vy);
    
    void setup();
    void resetForce();
    void applyForce(ofVec2f force);
    
    void update(ofVec2f myPos);
    void draw(ofColor _color);
    
    ofVec2f pos, vel, acc;
    float lifespan;
    float size;
    
    float pct;
    float rad;
   
};
