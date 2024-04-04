#pragma once

#include "ofMain.h"

using namespace glm;

class Fractal3D {
    private:
        ofMesh mesh;
        ofEasyCam* cam;
        bool currentMeshHasDetail = false;
        bool extrudeAllFaces = false;
    public:
        Fractal3D(ofEasyCam* cam);
        ~Fractal3D();

        vec3 centerOf(vector<vec3>& points);


        void draw(map<string, float>);
        void generateTetrahedron(vector<vec3>& base, vec3 peak, int n);
        void reset();
        map<string, float> getDefaultConfig();
        void toggleDetail();
};