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
    sunflower= new SunflowerFractal("SunFlower Fractal");
    cherryblossoms= new CherryBlossoms("Cherry Blossoms Fractal");
    bubbles=  new Bubbles("Cherry Blossoms Fractal");
   


    circle->setLevel(1);
    tree->setLevel(1);
    triangle->setLevel(1);
    barnsley->setLevel(6);
    snowflake->setLevel(6);
    fractal3d->setLevel(0);
    sunflower->setLevel(0);
    cherryblossoms->setLevel(0);
    bubbles->setLevel(0);
    


    new_vector = {circle,tree,triangle,barnsley,snowflake,fractal3d,sunflower,cherryblossoms,bubbles};

}
//--------------------------------------------------------------
void ofApp::update() {

    if(isAnimating){
        Counter++;
        if(Counter>=frame){
            Counter=0;
            if (mode>='1' && mode<='9'){
                int index = mode-'1';
                int currentLevel = new_vector[index]->getLevel();
                int maxLevel = 5;
                if(mode=='1'){
                    maxLevel =5;
                }
                else if(mode=='2'){
                    maxLevel =15;
                }
                 else if(mode=='3'){
                    maxLevel =10;
                }
                 else if(mode=='4'){
                    maxLevel =10;
                }
                 else if(mode=='5'){
                    maxLevel =6;
                }
                 else if(mode=='6'){
                    maxLevel =9;
                }
                else if(mode=='7'){
                    maxLevel =82;
                }
                else if(mode=='8'){
                    maxLevel =18;
                }
                else if(mode=='9'){
                    maxLevel=5;
                }

                
                currentLevel+= animationdirection; 
                if(currentLevel>=maxLevel){
                    currentLevel = maxLevel;
                    animationdirection=-1;
                }
                else if(currentLevel<1){
                    currentLevel = 1;
                    animationdirection = 1;
                }
                new_vector[index]->setLevel(currentLevel);
        }
    }
 }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor(65), ofColor(0), OF_GRADIENT_BAR);

    ofNoFill();
    switch (mode) {
    case '1': {
        // Circle
        new_vector[0]->draw();
        ofSetColor(ofColor::white); 
        text.drawString("Circle Fractal",25,60);
        
    } break;
    case '2': {
        // Tree 

        new_vector[1]->draw();
        ofSetColor(ofColor::white); 
        text.drawString("Tree Fractal",25,60);
     
     
    } break;
    case '3': {
        // Sierpinski Triangle
        new_vector[2]->draw();
        ofSetColor(ofColor::white); 
        text.drawString("Sierpinksi Triange Fractal",25,60);

    } break;
    case '4': {
        // Barnsley Fern
        new_vector[3]->draw();
        ofSetColor(ofColor::white); 
        text.drawString("Barnsley Fern Fractal",25,60);
        // drawMode4(0, 0, barnsleyLevels * 1000);
    }    break;
    case '5': {
        // Koch SnowFlake
        
        new_vector[4]->draw();
        ofSetColor(ofColor::white); 
        text.drawString("Koch SnowFlake Fractal",25,60);
      
    }   break; 
    case '6': {
        //3d Fractal
        new_vector[5]->draw();
        ofSetColor(ofColor::white); 
        text.drawString("3d Fractal",25,60);
    }   break;
     case '7':{
        // SunFlowerFractal
        new_vector[6]->draw();
        ofSetColor(ofColor::white); 
        text.drawString("SunFlower Fractal",25,60);
        
    } break;
    case '8':{
        // CherryBlossomFractal
        new_vector[7]->draw();
        ofSetColor(ofColor::white); 
        text.drawString("Cherry Blossoms Fractal",25,60);
    } break;
    case '9':{
        // BubblesFractal
        new_vector[8]->draw();
        ofSetColor(ofColor::white); 
        text.drawString("Bubbles Fractal",25,60);
    } break;

    }


    if (showInfo) {
        string info;
        info += " 1. Circle Level: " + to_string(circle->getLevel()) + "\n\n";
        info += " 2. Tree Level: " + to_string(tree->getLevel()) + "\n\n";
        info += " 3. Sierpinski Triangle Level: " + to_string(triangle->getLevel()) + "\n]\n";
        info += " 4. Barnsley Fern Level: " + to_string(barnsley->getLevel()) + "\n\n";
        info += " 5. Koch SnowFlake Level : " + to_string(snowflake->getLevel()) + "\n\n";
        info += " 6. 3D Fractal Level : " + to_string(fractal3d->getLevel()) + "\n\n";
        info += " 7. SunFlower Fractal: " + to_string(sunflower->getLevel()) + "\n\n";
        info += " 8. Cherry Blossoms Fractal: " + to_string(cherryblossoms->getLevel()) + "\n\n";
        info += " 9.Bubbles Fractal:" + to_string(bubbles->getLevel()) + "\n\n";



        dataText.drawString("Press the right arrow to level up the recursion",1025,40);
        dataText.drawString("Press the left arrow to level down the recursion",1025,80);
    
        ofSetColor(255);
        dataText.drawString(info, 25, 140);
    }
    ofSetColor(255);
} 

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key >= '1' && key <= '9'){
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
        else if (mode == '7' && sunflower->getLevel() >0)
            sunflower->setLevel(sunflower->getLevel()-1);
        else if (mode == '8' && cherryblossoms->getLevel() >0)
            cherryblossoms->setLevel(cherryblossoms->getLevel()-1);
        else if (mode == '9' && bubbles->getLevel() >0)
            bubbles->setLevel(bubbles->getLevel()-1);
        
     
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
        else if (mode == '7' && sunflower->getLevel() < 82)
            sunflower->setLevel(sunflower->getLevel()+1);
        else if (mode == '8' && cherryblossoms->getLevel() < 20)
            cherryblossoms->setLevel(cherryblossoms->getLevel()+1);
        else if (mode == '9' && bubbles->getLevel() < 5)
            bubbles->setLevel(bubbles->getLevel()+1);
        
    }   //Starts animation sequence
        else if(key == ' '){
            if (!isAnimating){
                isAnimating=true;
                Counter=0;
                animationdirection = 1;
            }
            else{
                isAnimating=false;
            }
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