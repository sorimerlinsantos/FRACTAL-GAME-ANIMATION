#include "AbstractFractal.h"


class CherryBlossoms: public AbstractFractal{
   
    public:
        CherryBlossoms();
        CherryBlossoms(string name): AbstractFractal(name){}

        //METHODS 

        void draw();
        void drawHelper(float x, float y, int n, float length, float rad);
       




};