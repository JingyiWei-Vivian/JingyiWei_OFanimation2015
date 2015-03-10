//
//  tail.cpp
//  w05_h01_Fireworks
//
//  Created by Vivian Wei 13" on 3/6/15.
//
//

#include "tail.h"

void tail::setup(){

}

void tail::update(float xPos, float yPos){
    
    myPoint.set(xPos, yPos);    
    points.push_back(myPoint);
    
    if (points.size() > 2000){
        points.erase(points.begin());
    }
}

void tail::draw(){
    
    ofBeginShape();
    ofNoFill();
    for (int i=0; i<points.size(); i++){
        
        ofVertex(points[i].x, points[i].y);
        ofSetColor(255, 255, 255, 255-i*2);
    }
    ofEndShape();
}


