//
//  Flowfield.h
//  w09_h01_3D
//
//  Created by Vivian Wei 13" on 4/26/15.
//
//

#pragma once

#include "ofMain.h"

//reference sims2014_week7_vectorField_3D

class Flowfield {
public:
    
    void setup (int _width, int _height, int _depth, int _resolution);
    void update ();
    void draw ();
    void setNoise();
    
    ofVec3f getForceAtPosition( ofVec3f pos );
    
    int width, height, depth, resolution;
    vector <vector <vector <ofVec3f> > > flowField;
    
};
