//
//  Particle.h
//  w05_h02_KnowledgeIsPower
//
//  Created by Vivian Wei 13" on 3/10/15.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    
    //built-in function: constractor, it's called by default
    //the difference between contractor and setup, setup is the function that needs to be called in order to run
    Particle(ofVec2f _pos);
    
    void resetForce();
    void applyForce(ofVec2f force);
    void update();
    void draw();
    
    ofVec2f acc, vel, pos;
    float lifespan;
};
