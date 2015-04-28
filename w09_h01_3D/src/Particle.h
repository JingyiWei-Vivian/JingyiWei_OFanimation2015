//
//  Particle.h
//  w09_h01_3D
//
//  Created by Vivian Wei 13" on 4/26/15.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    
    void setup();
    void resetForce();
    void applyForce(ofVec3f force);
    void applyDampingForce(float damping);
    
    void update();
    void draw();
    
    ofVec3f pos;
    ofVec3f vel;
    ofVec3f acc;
};
