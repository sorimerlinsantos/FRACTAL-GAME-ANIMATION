#include "AbstractFractal.h"


// class AbstractFractal: public Fractal{
//     private:
//         string name;
//         int level; 
//     public:

// de la clase de abstract fractal se va a crear el constructor de abstract fractal


//la clase esta en el .h por lo que tienes que decirle de donde viene esos metodos

AbstractFractal::AbstractFractal(){
            this->name="";
            // this->level=0;
        }
AbstractFractal::AbstractFractal(string name){
    this->name=name;
    // this->level=level; 

}
// //getters 
// string AbstractFractal::getName(){return name;}
// int AbstractFractal::getLevel(){return level;}
// //setters 
// void AbstractFractal::setName(string name){this->name=name;}
// void AbstractFractal::setLevel(int level){this->level=level;}
// //
