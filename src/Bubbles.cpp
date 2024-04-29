
#include "Bubbles.h"




void Bubbles::drawHelper(int currentSeed, int numSeeds, float centerX, float centerY, float scalingFactor) {
    if (currentSeed >= numSeeds) {
        return; 
    }

    float goldenAngle = 90.5;
    float radius = sqrt(currentSeed) * scalingFactor;
    float angle = currentSeed * goldenAngle * PI / 180.0; 
    float x = centerX + radius * cos(angle);
    float y = centerY + radius * sin(angle);
    
    ofSetColor(ofColor::blueSteel);  
    ofDrawCircle(x, y, 10); 


    drawHelper(currentSeed + 1, numSeeds, x, y, scalingFactor);
    drawHelper(currentSeed + 3, numSeeds, x, y, scalingFactor);
    //drawHelper(currentSeed + 5, numSeeds, x, y, scalingFactor);
}
void Bubbles::draw() {
   
    float centerX = ofGetWidth() / 2;
    float centerY = ofGetHeight() / 2;
    
    float scalingFactor = 40.0;

    drawHelper(0, this->getLevel()*5, centerX, centerY, scalingFactor);


}


 