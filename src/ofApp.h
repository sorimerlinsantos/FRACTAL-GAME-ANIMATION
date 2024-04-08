#pragma once

#include <cmath>

#include "ofMain.h"

class ofApp : public ofBaseApp {
  private:
    char mode = '1';
    int levels = 1;
    int circleLevels = 1;
    int treeLevels = 1;
    int triangleLevels = 1;
    int barnsleyLevels = 5;
    int snowflakeLevels = 1;
    int fractal3DLevels= 0;
    float size = 0.74 * ofGetHeight(); 
    bool showInfo = false;
    float angle = 0;



  public:
    void setup();
    void update();
    void draw();
    
    
    glm::vec2 p1 = {(ofGetWidth() - size) / 2, (ofGetHeight() - size * sin(PI / 3)) / 2 + 0.15 * size};
    glm::vec2 p2 = {(ofGetWidth() + size) / 2, (ofGetHeight() - size * sin(PI / 3)) / 2 + 0.15 * size};
    glm::vec2 p3 = {ofGetWidth() / 2, (ofGetHeight() + size * sin(PI / 3)) / 2 + 0.15 * size}; 

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    void drawMode1(float x, float y, float r, int n, ofColor color);
    void drawMode2(float x, float y, int n, float length, float rad,ofColor color);
    void drawMode3(float x, float y, float size, int n, ofColor color);
    void drawMode4(float x, float y, float n);

    ofEasyCam cam;
    ofTrueTypeFont text;
    ofTrueTypeFont dataText;
    ofColor color;
};
