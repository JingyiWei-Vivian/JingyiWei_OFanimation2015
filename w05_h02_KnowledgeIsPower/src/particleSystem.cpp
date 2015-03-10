//
//  particleSystem.cpp
//  w05_h02_KnowledgeIsPower
//
//  Created by Vivian Wei 13" on 3/10/15.
//
//

#include "particleSystem.h"

particleSystem:: particleSystem(ofVec2f _pos){
    
    pos.set(_pos);
}

//--------------------------------------------------------------
void particleSystem::update(ofVec2f _force){
    
    
    for (int i=0; i<10; i++){
        
        Particle particle(pos);
        particleList.push_back(particle);
    }
    
    ofVec2f mousePos = ofVec2f(ofGetMouseX(), ofGetMouseY());
    
    for (int i=0; i<particleList.size(); i++){
        
        ofVec2f diff = mousePos - particleList[i].pos;
        attraction.set(diff.getNormalized()*0.3);
        
        particleList[i].resetForce();
        particleList[i].applyForce(attraction);
        particleList[i].update();
        
    }

    while (particleList.size() > 3000){
        particleList.erase(particleList.begin());
    }
    
}

//--------------------------------------------------------------
void particleSystem::draw(){
    
    
    for (int i=0; i<particleList.size(); i++){

            particleList[i].draw();
            ofLine(particleList[i].pos.x, particleList[i].pos.y, particleList[i-1].pos.x, particleList[i-1].pos.y);
    }

}
