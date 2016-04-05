//
//  Leaf.h
//  Origami_Hanami
//
//  Created by Ryota Katoh on 4/6/16.
//
//

#ifndef Leaf_h
#define Leaf_h

#include "ofMain.h"

class Leaf{
public:
    
    Leaf(ofImage *img, ofVec3f *force){
        leafImage = img;
        externalForce = force;
        
        init();
        
    }
    
    void update(){
        position += speed + *externalForce*externalForceFriction;
        
    };
    void draw(){
        ofPushMatrix();
        ofTranslate(position);
        ofRotate(sin(ofGetFrameNum()*rotateFriction/PI + rotatePhase)*360, 1.0, 1.0, 1.0);
        
        leafImage->draw(0, 0);
        ofPopMatrix();
    };
    
    void init(){
        speed = ofVec3f(0.0, ofRandom(-5.0, -1.0), 0.0);
        position = ofVec3f(ofRandom(-4000, 4000), 1000, ofRandom(-4000, 4000));
        
        rotateSpeed = ofVec3f(ofRandom(-1.0, 1.0), ofRandom(-1.0, 1.0), ofRandom(-1.0, 1.0));
        
        externalForceFriction = ofRandom(0.01, 0.3);
        rotateFriction = ofRandom(0.01, 0.1);
        rotatePhase = ofRandom(-2.0, 2.0);
        
    }
    
    ofImage *leafImage;
    ofVec3f *externalForce;
    ofVec3f rotateSpeed;
    ofVec3f rotate;
    ofVec3f speed;
    ofVec3f position;
    
    float externalForceFriction;
    float rotateFriction;
    float rotatePhase;
    
};

#endif /* Leaf_h */
