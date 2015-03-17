//
//  Particle.cpp
//  Midterm
//
//  Created by Vivian Wei 13" on 3/15/15.
//
//

#include "Particle.h"

Particle::Particle(ofVec2f _pos, float vx, float vy){
    
    pos.set(_pos);
    vel.set(vx, vy);
    lifespan = ofRandom(155, 255);
    size = ofRandom(5, 20);
}

void Particle::setup(){
    
}

void Particle::resetForce(){
    
    acc *= 0;
}

void Particle::applyForce(ofVec2f force){
    
    acc += force;
}

void Particle::update(ofVec2f myPos){
    
    vel += acc;
    //pos += vel;
    pos = (pos*(1-pct) + myPos*pct) + vel;
    
    if(lifespan>0) {
        lifespan -= 3.0;
    }
}

void Particle::draw(ofColor _color){
    
    ofSetColor(_color, lifespan);
    ofCircle(pos, size);

}

