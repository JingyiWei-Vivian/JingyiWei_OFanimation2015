//
//  tool.cpp
//  w03_h01_JingyiWei
//
//  Created by Vivian Wei 13" on 2/12/15.
//
//

#include "tool.h"

void tool::setup(){

}

void tool::update(){
    
    //set random "splatters"
    int choice = ofRandom(4);
    
    if (choice == 1){
        
        ofSetColor(0, 0, 0, ofRandom(120, 255));
        rad = ofRandom(1, 4);
    }
    
    if (choice == 2) {
        
        ofSetColor(255, 255, 0, ofRandom(120, 255));
        rad = ofRandom(5, 7);
    }
    
    if (choice == 3) {

        ofSetColor(215, 50, 50, ofRandom(120, 255));
        rad = ofRandom(8, 10);
    }
}

void tool::draw(){

    ofCircle(start.x + ofRandom(10,30), start.y + ofRandom(10,50), rad);
}
