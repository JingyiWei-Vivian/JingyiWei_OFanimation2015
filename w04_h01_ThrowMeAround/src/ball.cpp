//
//  ball.cpp
//  w04_h01_ThrowMeAround
//
//  Created by Vivian Wei 13" on 2/25/15.
//
//

#include "ball.h"

//setup initial pos and mass
void ball::setup(float x, float y, float _mass){
    
    pos.set(x, y);
    mass = _mass;
}

//reset acc so it starts from 0
void ball::resetForces(){
    
    acc *= 0;
}

//apply force, and add to acc
void ball::applyForce(ofVec2f _force){
    
    force = _force;
    acc = acc + force/mass;
}

//apply damping force so it slows down
void ball::applyDampingForce(float damping){
    
    acc = acc - vel.getNormalized() * damping;
}

//limit the moving area
void ball::update(){
    
    vel = vel + acc;
    pos = pos + vel;
    
    if (pos.x < 0){
        pos.x = 0;
        vel.x *= -1;
    }
    
    if (pos.x > ofGetWidth()){
        pos.x = ofGetWidth();
        vel.x *= -1;
    }
    
    if (pos.y < 0){
        pos.y = 0;
        vel.y *= -1;
    }
    
    if (pos.y > ofGetHeight()){
        pos.y = ofGetHeight();
        vel.y *= -1;
    }
    
}

//draw the ball
void ball::draw(){
    
    ofCircle(pos, 10*mass);
}

