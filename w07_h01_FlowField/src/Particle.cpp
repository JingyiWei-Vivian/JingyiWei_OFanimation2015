//
//  Particle.cpp
//  w07_h01_FlowField
//
//  Created by Vivian Wei 13" on 4/6/15.
//
//

#include "Particle.h"

void Particle::setup(){
    
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
}

void Particle::resetForces(){
    
    acc *= 0;
}

void Particle::applyForce(ofVec2f force){
    
    acc += force;
}

void Particle::applyDampingForce(float damping){
    
    acc -= vel.getNormalized() * damping;
}

void Particle::update(){
    
    vel += acc;
    pos += vel;
}

void Particle::draw(){
    
    ofCircle(pos, 1);
}


