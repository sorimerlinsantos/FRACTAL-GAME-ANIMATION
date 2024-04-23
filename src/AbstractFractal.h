#pragma once
#include "Fractal.h"

//DE EL ABSTRACT FRACTAL SE HACE INHERITANCE A EL FRACTAL QUE ES DE MAYOR IMPORTANCIA DESPUES DEL MAIN.H 


class AbstractFractal: public Fractal {
    private:
        string name;
        int level; 
    //      char mode = '1';
    // int levels = 1;
    // int circleLevels = 1;
    // int treeLevels = 1;
    // int triangleLevels = 1;
    // int barnsleyLevels = 5;
    // int snowflakeLevels = 1;
    // int fractal3DLevels= 0;
    // float size = 0.74 * ofGetHeight(); 
    // bool showInfo = false;
    public:
        //NO ES NECESARIO KEEP AN EYE IN IT....
        AbstractFractal();
        AbstractFractal(string name);

        //getters 
        string getName(){return name;}
        virtual int getLevel(){return level;}
        // int getLevel(){return level;}

        //setters
        void setName(string name){this->name=name;}
        virtual void setLevel(int level){this->level=level;}
        // void setLevel(int level){this->level=level;}

        //no puedes dibujar algo que no conoces
        //si trataras de instanciarla entonces ahi te daria un error, ya que no tenemos el draw implementado, pero las clases abstractas no se instancian

};