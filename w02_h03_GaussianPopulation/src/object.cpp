//
//  object.cpp
//  w03_h03_JingyiWei
//
//  Created by Vivian Wei 13" on 2/17/15.
//
//

#include "object.h"

void object::setup(){

}

void object::update(ofVec2f P){
    
    pos = pos * 0.9 + 0.1* P;
}

void object::draw(){
    
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetColor(255);
    ofCircle(pos.x, pos.y, 30);
    ofCircle(pos.x, pos.y+60, 50);
    ofRotate(-20);
    ofSetColor(0);
    ofRect(15,20, 50, 10);
    ofRotate(40);
    ofRect(-65, 20, 50, 10);
    ofPopMatrix();

}