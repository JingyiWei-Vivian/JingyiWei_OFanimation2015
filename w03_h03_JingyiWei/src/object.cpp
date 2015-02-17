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

void object::update(){
    
}

void object::draw(float xPos, float yPos){
    
    xPos =0;
    yPos =0;
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetColor(255);
//    ofCircle(0, 0, 30);
//    ofCircle(0, 60, 50);
    
    ofCircle(xPos, yPos, 30);
    ofCircle(xPos, yPos+60, 50);
    ofRotate(-20);
    ofSetColor(0);
    ofRect(15,20, 50, 10);
    ofRotate(40);
    ofRect(-65, 20, 50, 10);
    ofPopMatrix();
}