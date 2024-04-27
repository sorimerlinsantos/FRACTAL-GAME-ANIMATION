#include "TriangleFractal.h"


void TriangleFractal::drawHelper(float x, float y, float size, int n) {
    if (n == 0) return;
    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    //drawHelper(x, y, size, n - 1);  
    drawHelper(x, y, size / 2, n - 1);
    drawHelper((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);
    //drawHelper((a.x + c.x)/2, (a.y+ c.y) / 2, size / 2, n - 1);

    // ofSetColor(color);
    // ofDrawTriangle(a, b, c);
    //  ofColor colors[] = {
    //     ofColor(0, 255, 0),     // Green
    //     ofColor(128, 0, 128),   // Purple
    //     ofColor(165, 42, 42), 
    //     // Add more colors as needed
    // };
    // ofColor nextColor = colors[n % (sizeof(colors) / sizeof(colors[0]))];

    //se rompe
    // drawHelper(x, y, size / 2, n - 1);
    // drawHelper((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);
    // if (n == 0) return;
    // if (n > 1 ) {
    //     ofSetColor(ofColor::green);
    // }
    if (n==1) {
        ofSetColor(ofColor::yellow);   
    }
    else if (n==2) {
        ofSetColor(ofColor::green);   
    } 
    else if (n==3) {
        ofSetColor(ofColor::red);   
    } 
    else if (n==4) {
        ofSetColor(ofColor::blue);   
    } else if (n  > 4  && n< 7) {
        ofSetColor(ofColor::red);    
    } else if(n > 12 && n<= 15 ){
        ofSetColor(ofColor::green); 
    }
    ofDrawTriangle(a, b, c);

    
    drawHelper((a.x + c.x)/2, (a.y+ c.y) / 2, size / 2, n - 1);

}


void TriangleFractal::draw(){
    float size = 0.88 * ofGetHeight();
    drawHelper((ofGetWidth() - size) / 2, ofGetHeight() / 2 - 0.4 * size, size, this->getLevel());
}



