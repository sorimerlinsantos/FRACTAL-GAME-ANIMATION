#include "AbstractFractal.h"


class BarnsleyFractals: public AbstractFractal{

    public:
        BarnsleyFractals();
        BarnsleyFractals(string name):AbstractFractal(name){}

        void draw();
        void drawHelper(float x, float y, float n);
};