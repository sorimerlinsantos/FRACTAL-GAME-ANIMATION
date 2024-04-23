#include "AbstractFractal.h"

class TreeFractal: public AbstractFractal{
    
    
    public:
        TreeFractal();
        TreeFractal(string name):AbstractFractal(name){}

        void draw();
        void drawHelper(float x, float y, int n, float length, float rad);
};


