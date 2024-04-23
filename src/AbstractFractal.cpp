#include "AbstractFractal.h"


// de la clase de abstract fractal se va a crear el constructor de abstract fractal


//la clase esta en el .h por lo que tienes que decirle de donde viene esos metodos

AbstractFractal::AbstractFractal(){
            this->name="";
        }
AbstractFractal::AbstractFractal(string name){
    this->name=name;
    

}

