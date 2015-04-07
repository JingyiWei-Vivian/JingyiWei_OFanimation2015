//
//  Particle.h
//  w07_h02_ParticlesWithFlowField
//
//  Created by Vivian Wei 13" on 4/7/15.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    
    void setup();
    
    void resetForces();
    void applyForce(ofVec2f force);
    void applyDampingForce(float damping);
    
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
    
};
