#include "SunflowerFractal.h"

void SunflowerFractal::draw() {
   
    float centerX = ofGetWidth() / 2;
    float centerY = ofGetHeight() / 2;
    
    float scalingFactor = 7.0;

   
    // drawSeed(0, this->getLevel()*25, centerX+100, centerY-200, 2.0,255,255,0);
    // drawSeed(0, this->getLevel()*25, centerX-100, centerY-200, 2.0,255,255,0);
    // drawSeed(0, this->getLevel()*25, centerX+100, centerY+200, 2.0,255,255,0);
    // drawSeed(0, this->getLevel()*25, centerX+100, centerY-200, 2.0,255,255,0);
    // drawSeed(0, this->getLevel()*25, centerX+100, centerY-200, 2.0,255,255,0);
    // drawSeed(0, this->getLevel()*25, centerX+100, centerY-200, 2.0,255,255,0);
    // drawSeed(0, this->getLevel()*25, centerX+100, centerY-200, 2.0,255,255,0);
    drawSeed(0, this->getLevel()*25, centerX, centerY, scalingFactor,210, 180, 140);
}

void SunflowerFractal::drawSeed(int currentSeed, int numSeeds, float centerX, float centerY, float scalingFactor, int r, int g, int b) {
    if (currentSeed >= numSeeds) {
        return; 
    }

    float goldenAngle = 137.5;
    float radius = sqrt(currentSeed) * scalingFactor;
    float angle = currentSeed * goldenAngle * PI / 180.0; 
    float x = centerX + radius * cos(angle);
    float y = centerY + radius * sin(angle);
    
    ofSetColor(r, g, b); 
    ofDrawCircle(x, y, 6); 


    drawSeed(currentSeed + 1, numSeeds, centerX, centerY, scalingFactor,r,g,b);
}