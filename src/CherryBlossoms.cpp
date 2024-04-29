    
#include "CherryBlossoms.h"  
    
    void CherryBlossoms::drawHelper(float x, float y, int n, float length, float rad) {


    // ofSetColor(color);
    float x2 = x + length * cos(rad);
    float y2 = y + length* sin(rad) ;

    ofDrawLine(x, y, x2, y2);
    if (n== 0) return;
    else if (n ==1 ) {
       ofSetColor(ofColor::pink);
    }
    else if (n ==2 ) {
       ofSetColor(ofColor::white);
    }
    else if (n ==3 ) {
       ofSetColor(ofColor::pink);
    }
    else if (n ==4 ) {
       ofSetColor(ofColor::white);
    }
    else if (n ==5 ) {
       ofSetColor(ofColor::pink);
    }
    else if (n ==6 ) {
       ofSetColor(ofColor::white);
    }
    else if (n >=7 && n<= 10 ) {
       ofSetColor(ofColor::pink);
    }
    else if (n >11) {
       ofSetColor(ofColor::white);
    }



    drawHelper(x2, y2,n - 1, 0.7 * length, rad + 0.2 * PI);
    drawHelper(x2, y2, n - 1, 0.7 * length, rad* PI);

}
 void CherryBlossoms::draw(){
    float length = 0.31 * ofGetHeight();
    drawHelper(ofGetWidth() / 2, ofGetHeight() -80, this->getLevel(), length, 1.5 * PI);

}
///is breaking itself
