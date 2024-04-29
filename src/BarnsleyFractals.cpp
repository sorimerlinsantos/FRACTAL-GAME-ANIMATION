#include "BarnsleyFractals.h"



void BarnsleyFractals::drawHelper(float x, float y, float n) {


    if (n == 0) return;

    float r = ofRandom(1);

    float px = ofMap(x, -2.1820, 2.6558, 0, ofGetWidth());
    float py = ofMap(y, 0, 9.9983, ofGetHeight(), 0);

    ofFill();
    
    if (n < 1000) {
        ofSetColor(ofColor::yellow);   
    } else if (n >= 1000 && n < 2000) {
        ofSetColor(ofColor::red);    
    }
    else if (n >= 2000 && n < 2500) {
        ofSetColor(ofColor::blue);    
    }
    else if (n >= 2000 && n < 3000) {
        ofSetColor(ofColor::yellow);    
    } 
    else if (n >=3000 && n < 4000) {
        ofSetColor(ofColor::green);    
    } 
    else if (n >=4000 && n < 5000) {
        ofSetColor(ofColor::red);    
    }
    else if (n >=5000 && n < 6000) {
        ofSetColor(ofColor::blue);    
    }
     
    ofDrawCircle(px, py, 0.6);

    if (r < 0.01)
        drawHelper(0, 0.16 * y, n - 1);

    else if (r < 0.86)
        drawHelper(0.85 * x + 0.04 * y, -0.04 * x + 0.85 * y + 1.6, n - 1);

    else if (r < 0.93)
        drawHelper(0.2 * x - 0.26 * y, 0.23 * x + 0.22 * y + 1.6, n - 1);

    else
        drawHelper(-0.15 * x + 0.28 * y, 0.26 * x + 0.24 * y + 0.44, n - 1);
}


void BarnsleyFractals::draw(){
    drawHelper(0, 0, this->getLevel() * 1000);


}

