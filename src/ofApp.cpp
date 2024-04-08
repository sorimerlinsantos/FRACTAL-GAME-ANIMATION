#include "ofApp.h"
#include "SnowFlake.h"
#include "Fractal3D.h"

//--------------------------------------------------------------
void ofApp::setup() {
    cam.setUpAxis({0,0,1});
    cam.setDistance(200);
    text.load("Fonts/fractalFont.otf",40);
    dataText.load("Fonts/fractalFont.otf",18);
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor(65), ofColor(0), OF_GRADIENT_BAR);

   dataText.drawString("Press the right arrow to level up the recursion",1025,40);
   dataText.drawString("Press the right arrow to level up the recursion",1025,80);

    ofNoFill();
    switch (mode) {
    case '1': {
        // Circle
        text.drawString("Circle Fractal",25,60);
        float r = 0.31 * ofGetHeight();
        angle += 0.01;
        drawMode1(ofGetWidth() / 2, ofGetHeight() / 2, r, circleLevels, ofColor (color));
    } break;
    case '2': {
        // Tree 
        //void ofApp::drawMode2(float x, float y, int n, float length, float rad,ofColor color)
         text.drawString("Tree Fractal",25,60);
        float length = 0.31 * ofGetHeight();
        float smaller_length= 0.10* ofGetHeight();

        drawMode2(ofGetWidth() / 2, ofGetHeight() - 20, treeLevels, length, 1.5 * PI, ofColor (color));
        drawMode2(ofGetWidth() /8, ofGetHeight() - 3, treeLevels,smaller_length , 1.5 * PI, ofColor (color));
        drawMode2(ofGetWidth()-180, ofGetHeight() - 3, treeLevels,smaller_length , 1.5 * PI, ofColor (color));

    } break;
    case '3': {
        // Sierpinski Triangle
         text.drawString("Sierpinksi Triange Fractal",25,60);
        float size = 0.88 * ofGetHeight();
        drawMode3((ofGetWidth() - size) / 2, ofGetHeight() / 2 - 0.4 * size, size, triangleLevels, ofColor (color));
    } break;
    case '4': {
        // Barnsley Fern
         text.drawString("Barnsley Fern Fractal",25,60);
        drawMode4(0, 0, barnsleyLevels * 1000);
    }    break;
    case '5': {
        // Koch SnowFlake
         text.drawString("Koch SnowFlake Fractal",25,60);
         ofSetColor(color);

        ofColor Color1 = ofColor(255, 0, 0);
        ofColor Color2 = ofColor(0, 255,0);
        ofColor Color3 = ofColor(0,0,255);
    
        SnowFlake().draw(snowflakeLevels,new SnowFlake(p1,p2), Color1);
        SnowFlake().draw(snowflakeLevels, new SnowFlake(p2, p3),Color2);
        SnowFlake().draw(snowflakeLevels, new SnowFlake(p3, p1), Color3);
    }   break; 
    case '6': {
        //3d Fractal
         text.drawString("3d Fractal",25,60);
        Fractal3D(&cam).draw(map<string, float> {{"n", fractal3DLevels}, {"scale", 100}});
    }   break;
    }


    if (showInfo) {
        string info;
        info += " 1. Circle Level: " + to_string(circleLevels) + "\n\n";
        info += " 2. Tree Level: " + to_string(treeLevels) + "\n\n";
        info += " 3. Sierpinski Triangle Level: " + to_string(triangleLevels) + "\n]\n";
        info += " 4. Barnsley Fern Level: " + to_string(barnsleyLevels) + "\n\n";
        info += " 5. Koch SnowFlake Level : " + to_string(snowflakeLevels) + "\n\n";
        info += " 6. 3D Fractal Level : " + to_string(fractal3DLevels) + "\n\n";

        ofSetColor(255);
        dataText.drawString(info, 25, 140);
    }
    ofSetColor(255);
} 

void ofApp::drawMode1(float x, float y, float r, int n,ofColor color){
    if (n == 0) return;

    int delta = r * 0.35;
    ofSetColor(color);
    ofDrawCircle(x, y, r);

    ofColor colors[] = {
        ofColor(255, 0, 0),   // Red
        ofColor(0, 255, 0),   // Green
        ofColor(0, 0, 255),   // Blue
        ofColor(255, 255, 0), // Yellow
        // Add more colors as needed
    };
    
    ofColor nextColor = colors[n % (sizeof(colors) / sizeof(colors[0]))];

    float angle1 = angle;
    float angle2 = PI / 3 + angle;
    float angle3 = PI + angle;
    float angle4 = 2 * PI / 3 + angle;
    float angle5 = 4 * PI / 3 + angle;
    float angle6 = 5 * PI / 3 + angle;
    drawMode1(x + r * cos(angle1), y + r * sin(angle1), delta, n - 1,nextColor);
    drawMode1(x + r * cos(angle2), y + r * sin(angle2), delta, n - 1,nextColor);
    drawMode1(x + r * cos(angle3), y + r * sin(angle3), delta, n - 1,nextColor);
    drawMode1(x + r * cos(angle4), y + r * sin(angle4), delta, n - 1,nextColor);
    drawMode1(x + r * cos(angle5), y + r * sin(angle5), delta, n - 1,nextColor);
    drawMode1(x + r * cos(angle6), y + r * sin(angle6), delta, n - 1,nextColor);
}

void ofApp::drawMode2(float x, float y, int n, float length, float rad,ofColor color) {
    if (n == 0) return;

    ofSetColor(color);
    float x2 = x + length * cos(rad);
    float y2 = y + length * sin(rad);

    ofDrawLine(x, y, x2, y2);
    ofColor colors[] = {
        ofColor(0, 255, 0),     // Green
        ofColor(128, 0, 128),   // Purple
        ofColor(165, 42, 42), 
        // Add more colors as needed
    };
    ofColor nextColor = colors[n % (sizeof(colors) / sizeof(colors[0]))];
    drawMode2(x2, y2, n - 1, 0.7 * length, rad + 0.2 * PI,nextColor);
    drawMode2(x2, y2, n - 1, 0.7 * length, rad - 0.2 * PI,nextColor);
}

void ofApp::drawMode3(float x, float y, float size, int n, ofColor color) {
    if (n == 0) {
        return;
    }
    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    ofSetColor(color);
    ofDrawTriangle(a, b, c);
     ofColor colors[] = {
        ofColor(0, 255, 0),     // Green
        ofColor(128, 0, 128),   // Purple
        ofColor(165, 42, 42), 
        // Add more colors as needed
    };
    ofColor nextColor = colors[n % (sizeof(colors) / sizeof(colors[0]))];


    drawMode3(x, y, size / 2, n - 1,nextColor);
    drawMode3((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1,nextColor);
    drawMode3((a.x + c.x)/2, (a.y+ c.y) / 2, size / 2, n - 1,nextColor);

}

void ofApp::drawMode4(float x, float y, float n) {
    if (n == 0) return;

    float r = ofRandom(1);

    float px = ofMap(x, -2.1820, 2.6558, 0, ofGetWidth());
    float py = ofMap(y, 0, 9.9983, ofGetHeight(), 0);

    ofFill();
    ofSetColor(ofColor::green); // Set color for this level
    ofDrawCircle(px, py, 0.6);
    ofSetColor(ofColor::white); // Reset color to white for consistency

    // Define an array of colors for each recursion level
    // ofColor colors[] = {
    //     ofColor(255, 0, 0),   // Red
    //     ofColor(0, 255, 0),   // Green
    //     ofColor(0, 0, 255),   // Blue
    //     ofColor(255, 255, 0), // Yellow
    //     // Add more colors as needed
    // };
    
    // // Get the color for the next recursion level
    // ofColor nextColor = colors[(int)n % (sizeof(colors) / sizeof(colors[0]))];

    if (r < 0.01)
        drawMode4(0, 0.16 * y, n - 1);

    else if (r < 0.86)
        drawMode4(0.85 * x + 0.04 * y, -0.04 * x + 0.85 * y + 1.6, n - 1);

    else if (r < 0.93)
        drawMode4(0.2 * x - 0.26 * y, 0.23 * x + 0.22 * y + 1.6, n - 1);

    else
        drawMode4(-0.15 * x + 0.28 * y, 0.26 * x + 0.24 * y + 0.44, n - 1);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key >= '1' && key <= '6'){
        mode = key;
    }
    if (key == OF_KEY_LEFT) {
        // Decrease depth of recursion
        if (mode == '1' && circleLevels > 1)
            circleLevels--;
        else if (mode == '2' && treeLevels > 1)
            treeLevels--;
        else if (mode == '3' && triangleLevels > 1)
           triangleLevels--;
        else if (mode == '4' && barnsleyLevels > 5)
            barnsleyLevels--;
        else if (mode == '5' && snowflakeLevels > 1)
            snowflakeLevels--;
        else if (mode == '6' && fractal3DLevels > 0)
            fractal3DLevels--;
    } else if (key == OF_KEY_RIGHT) {
        // Increase depth of recursion
        if (mode == '1' && circleLevels < 5)
            circleLevels++;
        else if (mode == '2' && treeLevels < 15)
            treeLevels++;
        else if (mode == '3' && triangleLevels < 10)
            triangleLevels++;
        else if (mode == '4' && barnsleyLevels < 50)
            barnsleyLevels++;
        else if (mode == '5' && snowflakeLevels < 6)
            snowflakeLevels++;
        else if (mode == '6' && fractal3DLevels < 9)
            fractal3DLevels++;
    }
    if (key == 'd') {
        showInfo = !showInfo;
    }
}



//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}