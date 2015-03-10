//
//  particle.cpp
//  w05_h01_Fireworks
//
//  Created by Vivian Wei 13" on 3/6/15.
//
//

#include "particle.h"

particle::particle(){

}

void particle::setup(float xPos, float yPos, float vx, float vy){
    
    pos.set(xPos, yPos);
    vel.set(vx, vy);
    
    tails.setup();
}

void particle::resetForce(){
    
    acc *= 0;
}

void particle::applyForce(ofVec2f force){
    
    acc += force;
}

void particle::applyDampingForce(float damping){
    
    damping = 0.05f;
    acc = acc - vel*damping;
}

void particle::update(){
    
    vel += acc;
    pos += vel;
    
    tails.update(pos.x, pos.y);
}

void particle::draw(){
    
    ofFill();
    ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), ofRandom(100, 255));
    ofCircle(pos, ofRandom(5, 10));
    
    tails.draw();
    
}
