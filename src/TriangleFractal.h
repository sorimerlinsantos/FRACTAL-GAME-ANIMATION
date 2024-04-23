#include "AbstractFractal.h"


class TriangleFractal: public AbstractFractal{
    public:
        TriangleFractal();
        TriangleFractal(string name):AbstractFractal(name){}
        void draw();
        void drawHelper(float x, float y, float size, int n);

};