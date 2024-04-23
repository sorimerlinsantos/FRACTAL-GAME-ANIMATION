#include "AbstractFractal.h"


class CircleFractal: public AbstractFractal{
    protected:
        float angle = 0;
      

    public:
        //constructor
        CircleFractal();
        CircleFractal(string name): AbstractFractal(name){}
        //functions 
        void draw();
        void drawHelper(float x, float y, float r, int n);
        // void setLevel();

    // LOS VALORES YA ESTAN SIENDO DECLARADOS POR LA FUNCION NO ES UN CONSTRUCTOR ES UN METODO, POR ESTO SE PUEDE HACER 
    //***************EL DRAW SE LLAMA IGUAL PORQUE ES UN PURE VIRTUAL FUNCTION, SE LLAMABN IGUAL Y SE IMPLEMENTAN OBLIGATORIAMENTE 
    //EN TODAS LAS SUBCLASES CON DIFERENTES "VALORES", EN ESTE CASO DIBUJO...
};
