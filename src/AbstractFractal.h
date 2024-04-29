#pragma once
#include "Fractal.h"


class AbstractFractal: public Fractal {
    private:
        string name;
        int level; 
    public:
       
        AbstractFractal();
        AbstractFractal(string name);

        //getters 
        string getName(){return name;}
        virtual int getLevel(){return level;}
     

        //setters
        void setName(string name){this->name=name;}
        virtual void setLevel(int level){this->level=level;}
        
};