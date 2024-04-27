#include "ofApp.h"
#include "SnowFlake.h"
#include "Fractal3D.h"

//--------------------------------------------------------------
void ofApp::setup() {
    cam.setUpAxis({0,0,1});
    cam.setDistance(200);
    text.load("Fonts/fractalFont.otf",40);
    dataText.load("Fonts/fractalFont.otf",18);




    circle= new CircleFractal("Circle Fractal");
    tree= new  TreeFractal("Tree Fractal");
    triangle= new TriangleFractal("Triangle Fractal");
    barnsley= new BarnsleyFractals("Barnsley Fractal");
    snowflake= new SnowFlake();
    fractal3d= new Fractal3D(&cam);
   


    circle->setLevel(1);
    tree->setLevel(1);
    triangle->setLevel(1);
    barnsley->setLevel(6);
    snowflake->setLevel(6);
    fractal3d->setLevel(0);


    new_vector = {circle,tree,triangle,barnsley,snowflake,fractal3d};

}
//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor(65), ofColor(0), OF_GRADIENT_BAR);

   dataText.drawString("Press the right arrow to level up the recursion",1025,40);
   dataText.drawString("Press the right arrow to level up the recursion",1025,80);

   // myVec = {circle, square, lightning}
   // myVec[0].draw()
   // myVec[mode-1].draw()

    ofNoFill();
    switch (mode) {
    case '1': {
        // Circle
        new_vector[0]->draw();
        text.drawString("Circle Fractal",25,60);
        
    } break;
    case '2': {
        // Tree 

        new_vector[1]->draw();
        text.drawString("Tree Fractal",25,60);
     
     
    } break;
    case '3': {
        // Sierpinski Triangle
        new_vector[2]->draw();
        text.drawString("Sierpinksi Triange Fractal",25,60);

    } break;
    case '4': {
        // Barnsley Fern
        new_vector[3]->draw();
        text.drawString("Barnsley Fern Fractal",25,60);
        // drawMode4(0, 0, barnsleyLevels * 1000);
    }    break;
    case '5': {
        // Koch SnowFlake
        //*******note**********
        //the recursion of snowflake no tiene un error, empieza en su nivel max
        new_vector[4]->draw();
        text.drawString("Koch SnowFlake Fractal",25,60);
      
    }   break; 
    case '6': {
        //3d Fractal
        new_vector[5]->draw();
        text.drawString("3d Fractal",25,60);
    }   break;
    }


    if (showInfo) {
        string info;
        info += " 1. Circle Level: " + to_string(circle->getLevel()) + "\n\n";
        info += " 2. Tree Level: " + to_string(tree->getLevel()) + "\n\n";
        info += " 3. Sierpinski Triangle Level: " + to_string(triangle->getLevel()) + "\n]\n";
        info += " 4. Barnsley Fern Level: " + to_string(barnsley->getLevel()) + "\n\n";
        info += " 5. Koch SnowFlake Level : " + to_string(snowflake->getLevel()) + "\n\n";
        info += " 6. 3D Fractal Level : " + to_string(fractal3d->getLevel()) + "\n\n";
       


        ofSetColor(255);
        dataText.drawString(info, 25, 140);
    }
    ofSetColor(255);
} 

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key >= '1' && key <= '6'){
        mode = key;
    }
    if (key == OF_KEY_LEFT) {
        // Decrease depth of recursion
        if (mode == '1' && circle->getLevel() > 1)
            circle->setLevel(circle->getLevel()-1);
        else if (mode == '2' && tree->getLevel() > 1)
            tree->setLevel(tree->getLevel()-1);
        else if (mode == '3' && triangle->getLevel() > 1)
           triangle->setLevel(triangle->getLevel()-1);
        else if (mode == '4' && barnsley->getLevel() > 1)
            barnsley->setLevel(barnsley->getLevel()-1);
        else if (mode == '5' && snowflake->getLevel() > 1)
            snowflake->setLevel(snowflake->getLevel()-1);
        else if (mode == '6' && fractal3d->getLevel() > 0)
            fractal3d->setLevel(fractal3d->getLevel()-1);
     
    } else if (key == OF_KEY_RIGHT) {
        // Increase depth of recursion
        if (mode == '1' && circle->getLevel() < 5)
            circle->setLevel(circle->getLevel()+1);
        else if (mode == '2' && tree->getLevel() < 15)
            tree->setLevel(tree->getLevel()+1);
        else if (mode == '3' &&triangle->getLevel() < 10)
            triangle->setLevel(triangle->getLevel()+1);
        else if (mode == '4' && barnsley->getLevel() < 10)
            barnsley->setLevel(barnsley->getLevel()+1);
        else if (mode == '5' && snowflake->getLevel() < 6)
            snowflake->setLevel(snowflake->getLevel()+1); 
        else if (mode == '6' && fractal3d->getLevel() < 9)
            fractal3d->setLevel(fractal3d->getLevel()+1);
        
            
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