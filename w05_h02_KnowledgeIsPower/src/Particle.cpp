//
//  Particle.cpp
//  w05_h02_KnowledgeIsPower
//
//  Created by Vivian Wei 13" on 3/10/15.
//
//

#include "Particle.h"

Particle::Particle(ofVec2f _pos){
    
    pos.set(_pos);
    vel.x = ofRandom(-1, 2);
    vel.y = ofRandom(-1, -5);
    lifespan = 255.0;
    
}

void Particle::resetForce(){
    
    acc *= 0;
}

void Particle::applyForce(ofVec2f force){
    
    acc += force;
}

void Particle::update(){
    
    vel += acc;
    pos += vel;
    
    if (lifespan > 0) {
        lifespan -= 3;
    }
}

void Particle::draw(){
    
    ofSetColor(lifespan);
    ofCircle(pos, 5);
}
