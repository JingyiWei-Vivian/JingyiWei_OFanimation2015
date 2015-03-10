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
    vel.y = ofRandom(-1, 2);
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
    
    float angle = ofRandom(0, 2*PI);
    float rad = ofRandom(1, 5);
    float posX = rad*sin(angle);
    float posY = rad*sin(angle);
    ofLine(posX, pos.y, pos.x, posY);
}
