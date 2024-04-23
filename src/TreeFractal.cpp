#include "TreeFractal.h"

    void TreeFractal::drawHelper(float x, float y, int n, float length, float rad) {

    


    // ofSetColor(color);
    float x2 = x + length * cos(rad);
    float y2 = y + length * sin(rad);

    // ofDrawLine(x, y, x2, y2);
    // ofColor colors[] = {
    //     ofColor(0, 255, 0),     // Green
    //     ofColor(128, 0, 128),   // Purple
    //     ofColor(165, 42, 42), 
    //     // Add more colors as needed
    // };
    // ofColor nextColor = colors[n % (sizeof(colors) / sizeof(colors[0]))];
    ofDrawLine(x, y, x2, y2);
    if (n<= 0) return;
    else if (n > 3) {
        ofSetColor(ofColor::green);
    } else if (n == 3) {
        ofSetColor(ofColor::blue);   
    } else if (n == 2) {
        ofSetColor(ofColor::red);    
    } else {
        ofSetColor(ofColor::yellow); 
    }

    drawHelper(x2, y2,n - 1, 0.7 * length, rad + 0.2 * PI);
    drawHelper(x2, y2, n - 1, 0.7 * length, rad - 0.2 * PI);
}
 void TreeFractal::draw(){
    float length = 0.31 * ofGetHeight();
    float smaller_length= 0.10* ofGetHeight();
    drawHelper(ofGetWidth() / 2, ofGetHeight() - 20, this->getLevel(), length, 1.5 * PI);
    drawHelper(ofGetWidth() /8, ofGetHeight() - 3, this->getLevel(),smaller_length , 1.5 * PI);
    drawHelper(ofGetWidth()-180, ofGetHeight() - 3, this->getLevel(),smaller_length , 1.5 * PI);
     


}
