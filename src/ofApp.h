#pragma once

#include "ofMain.h"
#include "Leaf.h"
#include "SVG.h"

#include "ofxGui.h"

//#define debug



class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    
    ofEasyCam camera;
    ofVec3f cameraPosition;
    vector<ofVec3f> cameraPositions;
    int cameraPositionNo;
    float cameraSpeed;
    ofVec3f cameraV;
    
    
    
    int numLeaves;
    ofImage leaf;
    vector<ofImage> leafImages;
    
    vector<Leaf> leaves;
    
    ofVec3f externalForce;
    int windFrameNum;
    
    
    SVG origamiLogo;
    
    ofxPanel gui;
    ofxVec3Slider svgPos;
    ofxVec3Slider cameraRoll;
    
    vector<int> logoImageNo;
    ofImage debugImage;
};
