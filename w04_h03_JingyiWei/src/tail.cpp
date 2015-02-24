//
//  tail.cpp
//  w04_h03_JingyiWei
//
//  Created by Vivian Wei 13" on 2/23/15.
//
//

#include "tail.h"

void tail::setup(){
    
    pos.set(0,0);
    
}

void tail::update(ofVec2f _dest){
    
    pos = pos * 0.9 + _dest * 0.1;

}

void tail::draw(float _alpha, float _size){

    ofSetColor(255,_alpha);
    ofCircle(pos.x, pos.y, _size);
    
    ofSetColor(255,20,125, 100);
    ofCircle(pos.x, pos.y+10, rad);
    ofSetColor(255,79,157,100);
    ofCircle(pos.x+5, pos.y+5, rad);
    
    ofSetColor(255,20,125,100);
    ofCircle(pos.x+5, pos.y-5, rad);
    ofSetColor(255,79,157,100);
    ofCircle(pos.x, pos.y-10, rad);
    
    

}