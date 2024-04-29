#include "SunflowerFractal.h"

void SunflowerFractal::draw() {
   
    float centerX = ofGetWidth() / 2;
    float centerY = ofGetHeight() / 2;
    
    float scalingFactor = 7.0;
   
    drawSeed(1, this->getLevel()*25, centerX, centerY, scalingFactor,255, 255, 0);
}

void SunflowerFractal::drawSeed(int currentSeed, int numSeeds, float centerX, float centerY, float scalingFactor, int r, int g, int b) {
     
    if (currentSeed >= numSeeds) {
        return; 
    }
    if (currentSeed > 0 && currentSeed<3*25) { 
        ofSetColor(101,67,33); 
    }
    else if (currentSeed > 4 && currentSeed<7*25) { 
        ofSetColor(125,75,31);  
    }
     else if (currentSeed > 8 && currentSeed<12*25) { 
        ofSetColor(150,90,30);  
    }
    else if (currentSeed > 13 && currentSeed<17*25) { 
        ofSetColor(181,101,29);  
    }

    else if(currentSeed>17*25 && currentSeed<20*25){
         ofSetColor(r, 25, b);
    }
    else if(currentSeed>20*25 && currentSeed<30*25){
        ofSetColor(r, 50, b); 
    } 
    else if(currentSeed>31*25 && currentSeed<41*25){
        ofSetColor(r, 75, b); 
    } 
    else if(currentSeed>42*25 && currentSeed<52*25){
        ofSetColor(r, 100, b); 
    } 
    else if(currentSeed>53*25 && currentSeed<63*25){
        ofSetColor(r, 125, b); 
    } 
    else if(currentSeed>64*25 && currentSeed<74*25){
        ofSetColor(r, 150, b); 
    } 
    else if(currentSeed>75*25 && currentSeed<87*25){
        ofSetColor(r, 200, b); 
    } 

    float goldenAngle = 137.5;
    float radius = sqrt(currentSeed) * scalingFactor;
    float angle = currentSeed * goldenAngle * PI / 180.0; 
    float x = centerX + radius * cos(angle);
    float y = centerY + radius * sin(angle);
    
    ofDrawCircle(x, y, 6); 
    drawSeed(currentSeed + 1, numSeeds, centerX, centerY, scalingFactor, r, g, b);
    
    


    
}