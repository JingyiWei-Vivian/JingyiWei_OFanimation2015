//
//  particleSystem.h
//  w05_h02_KnowledgeIsPower
//
//  Created by Vivian Wei 13" on 3/10/15.
//
//

#pragma once
#include "ofMain.h"
#include "Particle.h"

class particleSystem {
public:
    
    particleSystem(ofVec2f _pos);
    void update(ofVec2f _force);
    void draw();
    
    vector<Particle> particleList;
    ofVec2f pos;
    
    ofVec2f attraction;
    
};
