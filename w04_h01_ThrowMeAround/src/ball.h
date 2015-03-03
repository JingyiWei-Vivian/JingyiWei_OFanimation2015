//
//  ball.h
//  w04_h01_ThrowMeAround
//
//  Created by Vivian Wei 13" on 2/25/15.
//
//

#pragma once
#include "ofMain.h"

class ball{
public:
    
    void setup(float x, float y, float _mass);
    void applyForce(ofVec2f _force);
    void resetForces();
    void applyDampingForce(float damping);
    void update();
    void draw();
    
    ofVec2f pos, vel, acc, force;
    float mass;
};