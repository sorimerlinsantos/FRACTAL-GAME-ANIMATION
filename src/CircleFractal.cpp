
#include "CircleFractal.h"


//incluyes un file cuando vas a heredar de esa clase o vas utilizar la clase en si 


void CircleFractal::drawHelper(float x, float y, float r, int n){
    
    float delta = r * 0.35;

    if (n == 0) return;
    else if (n > 3) {
        ofSetColor(ofColor::green);
    } else if (n == 3) {
        ofSetColor(ofColor::blue);   
    } else if (n == 2) {
        ofSetColor(ofColor::red);    
    } else {
        ofSetColor(ofColor::yellow); 
    }


    ofDrawCircle(x, y, r);

    float angle1 = angle;
    float angle2 = PI / 3 + angle;
    float angle3 = PI + angle;
    float angle4 = 2 * PI / 3 + angle;
    float angle5 = 4 * PI / 3 + angle;
    float angle6 = 5 * PI / 3 + angle;
    drawHelper(x + r * cos(angle1), y + r * sin(angle1), delta, n - 1);
    drawHelper(x + r * cos(angle2), y + r * sin(angle2), delta, n - 1);
    drawHelper(x + r * cos(angle3), y + r * sin(angle3), delta, n - 1);
    drawHelper(x + r * cos(angle4), y + r * sin(angle4), delta, n - 1);
    drawHelper(x + r * cos(angle5), y + r * sin(angle5), delta, n - 1);
    drawHelper(x + r * cos(angle6), y + r * sin(angle6), delta, n - 1);


}

void CircleFractal::draw(){
    angle+=0.01;
    float r = 0.31 * ofGetHeight();
    drawHelper(ofGetWidth() / 2, ofGetHeight() / 2, r, this->getLevel());
    

}


