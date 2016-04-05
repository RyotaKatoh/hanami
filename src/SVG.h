//
//  SVG.h
//  Origami_Hanami
//
//  Created by Ryota Katoh on 4/6/16.
//
//

#ifndef SVG_h
#define SVG_h

#include "ofMain.h"
#include "ofxSVG.h"

class SVG{
public:
    
    void setup(string filePath, int numPoints){
        svgImage.load(filePath);
        
        offsetX = ofGetWidth() / 2. - svgImage.getWidth()/2.;
        offsetY = ofGetHeight() / 2. - svgImage.getHeight()/2.;
        
        int numPoly = 0;
        for(int i=0;i<svgImage.getNumPath();i++){
            ofPath &path = svgImage.getPathAt(i);
            path.setPolyWindingMode(OF_POLY_WINDING_ODD);
            const vector<ofPolyline> &polys = const_cast<vector<ofPolyline>&> (path.getOutline());
            for(int j=0;j<polys.size();j++){
                numPoly ++;
            }
        }
        
        int numPointsByPoly = numPoints / (float) numPoly + 1;
        
        for(int i=0;i<svgImage.getNumPath();i++){
            ofPath &path = svgImage.getPathAt(i);
            path.setPolyWindingMode(OF_POLY_WINDING_ODD);
            const vector<ofPolyline> &polys = const_cast<vector<ofPolyline>&> (path.getOutline());
            
            for(int j=0;j<polys.size();j++){
                for(int k=0;k<numPointsByPoly;k++){
                    ofPoint p = polys[j].getPointAtPercent(k/(float)numPointsByPoly);
                    p += ofPoint(offsetX, offsetY);
                    //points.push_back(ofVec3f(p.x, -300, p.y));
                    points.push_back(p);
                }
            }
        }
        
    }
    
    
    ofxSVG svgImage;
    vector<ofVec3f> points;
    
    float offsetX;
    float offsetY;
};

#endif /* SVG_h */
