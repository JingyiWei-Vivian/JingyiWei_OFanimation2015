//
//  Flowfield.cpp
//  w09_h01_3D
//
//  Created by Vivian Wei 13" on 4/26/15.
//
//
#include "Flowfield.h"

//reference sims2014_week7_vectorField_3D

void Flowfield::setup ( int _width, int _height, int _depth, int _resolution ) {
    
    width = _width;
    height = _height;
    depth = _depth;
    resolution = _resolution;
    
    int dirX = width / resolution;
    int dirY = height/ resolution;
    int dirZ = depth / resolution;
    
    for (int x=0; x<dirX; x++){
        vector <vector <ofVec3f> > flowFieldX;
        flowField.push_back(flowFieldX);
        
        for (int y=0; y<dirY; y++){
            vector <ofVec3f> flowFieldY;
            flowField[x].push_back(flowFieldY);
            
            for (int z=0; z<dirZ; z++){
                ofVec3f flowFieldZ;
                flowField[x][y].push_back(flowFieldZ);
            }
        }
    }
    
}

void Flowfield::draw () {
    
    for (int x=0; x<flowField.size(); x++){
        
        for (int y=0; y<flowField[x].size(); y++){
            
            for (int z=0; z<flowField[x][y].size(); z++){
                
                ofVec3f point(x*resolution, y*resolution, z*resolution);
                
                ofLine(point, point+flowField[x][y][z]);
            }
        }
    }
    
}

void Flowfield::setNoise() {
    
    for (int x=0; x<flowField.size(); x++){
        
        for (int y=0; y<flowField[x].size(); y++){
            
            for (int z=0; z<flowField[x][y].size(); z++){
                
                float noise = ofMap(ofNoise(x*0.1, y*0.1, z*0.1), 0.0, 1.0, 0.0, TWO_PI);
                
                flowField[x][y][z].set(ofVec3f (sin(noise)*20, cos(noise)*20, sin(noise)*20));
            }
        }
    }
    
}

ofVec3f Flowfield::getForceAtPosition(ofVec3f pos){
    
    float posX = pos.x / width;
    float posY = pos.y / height;
    float posZ = pos.z / depth;
    
    int dirX = width / resolution;
    int dirY = height / resolution;
    int dirZ = depth / resolution;
    
    int Xpos = ofClamp( posX * dirX, 0, dirX-1 );
    int Ypos = ofClamp( posY * dirY, 0, dirY-1 );
    int Zpos = ofClamp( posZ * dirZ, 0, dirZ-1 );
    
    ofVec3f newPos;
    newPos.set(flowField[Xpos][Ypos][Zpos]);
    
    return newPos;
}