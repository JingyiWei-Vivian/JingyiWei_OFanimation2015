//
//  Particle.cpp
//  w09_h01_3D
//
//  Created by Vivian Wei 13" on 4/26/15.
//
//

#include "Particle.h"

void Particle::setup(){
    
}

void Particle::resetForce(){
    acc *= 0;
}

void Particle::applyForce(ofVec3f force){
    acc += force;
}

void Particle::applyDampingForce(float damping){
    
    acc -= vel.getNormalized() * damping;
}

void Particle::update(){
    vel += acc;
    pos += vel;
    
    if(pos.x>1000) pos.x=1000;
    if(pos.y>1000) pos.y=1000;
    if(pos.z>1000) pos.z=1000;
    if(pos.x<0) pos.x=0;
    if(pos.y<0) pos.y=0;
    if(pos.z<0) pos.z=0;
}

void Particle::draw() {
    
    ofCircle(pos, 3);
}
