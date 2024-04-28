#include "AbstractFractal.h"

class SunflowerFractal : public AbstractFractal {
public:
    SunflowerFractal();
    SunflowerFractal(string name):AbstractFractal(name){}

    void draw(); 
    void drawSeed(int currentSeed, int numSeeds, float centerX, float centerY, float scalingFactor, int r, int g, int b);
};