
#pragma once
#include "ofMain.h"

// OF MAIN.H VIENE DE FRAMEWORKS, Y ES LA RAMA BASE;
class Fractal{
    public:
        virtual void draw()=0;
        virtual string getName()=0;
        virtual int getLevel()=0;

        virtual void setName(string name)=0;
        virtual void setLevel(int level)=0;
};