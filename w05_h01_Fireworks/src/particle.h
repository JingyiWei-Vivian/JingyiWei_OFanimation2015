//
//  particle.h
//  w05_h01_Fireworks
//
//  Created by Vivian Wei 13" on 3/6/15.
//
//

#pragma once
#include "ofMain.h"
#include "tail.h"

class particle{
public:
    
    particle();
    
    void setup(float xPos, float yPos, float vx, float vy);
    void resetForce();
    void applyForce(ofVec2f force);
    void applyDampingForce(float damping);
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
    
    tail tails;
};