#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofToggleFullscreen();
    
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetVerticalSync(true);

    cameraPositionNo = 4;//0;
    cameraSpeed = 0.2;
    cameraV = ofVec3f(0.0, 0.0, 0.0);

    cameraPositions.push_back(ofVec3f(300, 100, -300));
    cameraPositions.push_back(ofVec3f(300, 100, 300));
    cameraPositions.push_back(ofVec3f(-300, 100, 300));
    cameraPositions.push_back(ofVec3f(-300, 100, -300));
    cameraPositions.push_back(ofVec3f(1.0, 500, 1.0));
    
    cameraPosition = cameraPositions[cameraPositionNo];
    camera.setPosition(cameraPosition);
    camera.lookAt(ofVec3f(0,0,0));
    
    
    numLeaves = 5000;
    externalForce = ofVec3f(10.0, 0.0, 0.0);
    windFrameNum = 0;
    
    leaf.load("img/leaf1.png");
    leaf.resize(20, 19);
    leafImages.push_back(leaf);
    leaf.load("img/leaf2.png");
    leaf.resize(20, 19);
    leafImages.push_back(leaf);
    leaf.load("img/leaf3.png");
    leaf.resize(20, 19);
    leafImages.push_back(leaf);
    

    for(int i=0;i<numLeaves;i++){
        int leafType = ofRandom((int)leafImages.size());
        Leaf l(&leafImages[leafType], &externalForce);
        leaves.push_back(l);
    }
    
    
    origamiLogo.setup("svg/OrigamiLogoOutlined.svg", 300);
    
    gui.setup();
    gui.add(svgPos.setup("svg pos", ofVec3f(0.0, -460, 650), ofVec3f(-1000, -1000, -1000), ofVec3f(1000, 1000, 1000)));
    gui.add(cameraRoll.setup("cameraRoll", ofVec3f(-90, 0.0, 0.0), ofVec3f(0.0, 0.0, 0.0), ofVec3f(360, 360, 360.0)));
    
    
    cameraV += (cameraPositions[cameraPositionNo] - cameraPosition)*cameraSpeed;
    cameraPosition += cameraV;
    cameraV *= 0.1;
    camera.setPosition(cameraPosition);
    camera.lookAt(ofVec3f(0.0, 0.0, 0.0));
//    cameraRoll = camera.getOrientationEuler();
    
    for(int i=0;i<origamiLogo.points.size();i++){
        logoImageNo.push_back(ofRandom(leafImages.size()));
    }
    
    
    ofHideCursor();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    // {{ WIND EFFECT
    if(ofGetFrameNum() % 600 == 0){
        windFrameNum = 1;
    }
    
    if(windFrameNum > 0){
        externalForce.y = sin(windFrameNum*0.1/PI)*30;
        windFrameNum ++;
        if(windFrameNum*0.1/PI >= PI){
            windFrameNum = 0;
        }
    }
    // }}
    
    // {{ CAMERA MOVEMENT
    if(ofGetFrameNum() % 720 == 0){
        cameraPositionNo = (int) ofRandom(4.0);
        if(ofGetFrameNum() != 0 && ofRandom(1.0) < 0.1)
            cameraPositionNo = 4;
    }
    
    cameraV += (cameraPositions[cameraPositionNo] - cameraPosition)*cameraSpeed;
    cameraPosition += cameraV;
    cameraV *= 0.1;
    camera.setPosition(cameraPosition);
    camera.lookAt(ofVec3f(0.0, 0.0, 0.0));

    if(cameraPositionNo == 4){

        camera.setOrientation(cameraRoll);
    }
    // }}

    for(int i=0;i<leaves.size();i++){
        leaves[i].update();
        if(leaves[i].position.y < -3000){
            leaves[i].init();
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    camera.begin();
    
#ifdef debug
    ofDrawAxis(100);
#endif
    
    for(int i=0;i<leaves.size();i++)
        leaves[i].draw();
    
    
    // {{ LOGO
    if(cameraPositionNo == 4){
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2.*-1, ofGetHeight()/2.);
        ofRotate(90, 1.0, 0.0, 0.0);
        ofTranslate(svgPos);
        //ofScale(1.0, -1.0);
        for(int i=0;i<origamiLogo.points.size();i++){
            ofSetColor(255, 255, 255);
            leafImages[logoImageNo[i]].draw(origamiLogo.points[i]);
        }
//        debugImage.draw(0, 0);
        ofPopMatrix();
    }
    // }}
    
    camera.end();

#ifdef debug
    gui.draw();
#endif
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == '1')
        cameraPositionNo = 0;
    else if(key == '2')
        cameraPositionNo = 1;
    else if(key == '3')
        cameraPositionNo = 2;
    else if(key == '4')
        cameraPositionNo = 3;
    else if(key == '5')
        cameraPositionNo = 4;

    if(key == 't')
        ofToggleFullscreen();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
