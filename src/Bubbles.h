#include "AbstractFractal.h" 


class Bubbles: public AbstractFractal{
    protected:
        float angle = 0;
      

    public:
        
        Bubbles();
        Bubbles(string name): AbstractFractal(name){}

        //METHODS
  
    void draw(); 
    void drawHelper(int currentSeed, int numSeeds, float centerX, float centerY, float scalingFactor);
        


};