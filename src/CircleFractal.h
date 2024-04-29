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
};
