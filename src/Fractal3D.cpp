#include "Fractal3d.h"


Fractal3D::Fractal3D(ofEasyCam* cam) : cam(cam){
    
}

Fractal3D::~Fractal3D() {
    mesh.clear();
}

vec3 Fractal3D::centerOf(vector<vec3>& points) {
    vec3 result;
    for (vec3 v : points) {
        result += v;
    }
    result /= points.size();
    return result;
}

void Fractal3D::draw(map<string, float> drawConfig) {
    if (!mesh.hasVertices() || currentMeshHasDetail != extrudeAllFaces) {
        float scale = drawConfig["scale"];
        vector<vec3> base = {
            {-0.866025 * scale, -0.5 * scale, 0},
            {0.866025 * scale,  -0.5 * scale, 0},
            {0,                  scale,       0}
        };
        vec3 peak = {0.0, 0.0, 1.41421 * scale / 2};
        reset();
        mesh.setMode(OF_PRIMITIVE_TRIANGLES);
        generateTetrahedron(base, peak, drawConfig["n"]);
        mesh.setupIndicesAuto();
        currentMeshHasDetail = extrudeAllFaces;
    }

    cam->begin();
    ofEnableDepthTest();

    mesh.drawFaces();
    ofSetColor(0);
    mesh.drawWireframe();
    ofSetColor(255);
    ofNoFill();
    ofDrawPlane(0, 0, 0.3, 800, 800);
    ofSetColor(255);
    ofDisableDepthTest();
    cam->end();

}

void Fractal3D::generateTetrahedron(vector<vec3>& base, vec3 peak, int n) {
    if (!n) return;
    // The base of our tetrahedron will be the midpoints of the base of its parent
    vec3 midpointA = (base[0] + base[1]) / 2;
    vec3 midpointB = (base[0] + base[2]) / 2;
    vec3 midpointC = (base[1] + base[2]) / 2;
    vec3 centerOfBase = centerOf(base);
    vector<vec3> tetraHedron = {base[0], base[1], base[2], peak};
    vec3 centerOfTetrahedron = centerOf(tetraHedron);

    // We calculate the height for convenience
    float height = length(peak - centerOfBase);
    vec3 temp1, temp2;

    // To generate each child tetrahedron, we choose each face with one of 
    // its vertices being the peak as their bases.
    // Then we have to figure out where their peaks should be.
    // To calculate where the peaks will be placed, we calculate the normal of the 
    //base of the new tetrahedron, the peak is the point you land on after moving half the height in 
    //the normal direction from the center of the base.
    vector<vec3> base1 = {midpointA, midpointB, peak};
    temp1 = midpointB - midpointA;
    temp2 = peak - midpointA;
    vec3 normal1 = normalize(cross(temp1, temp2));

    if (distance(centerOf(base1), centerOfTetrahedron) > distance(centerOf(base1) + normal1 / 100, centerOfTetrahedron))
        normal1 *= -1; // Since the normal could point in the wrong direction, we check to see if moving a small amount along the calculated normal from the point of the new base puts us closer or farther from the center of our tetrahedron.

    vec3 peak1 = normal1 * height / 2 + centerOf(base1);

    vector<vec3> base2 = {midpointA, midpointC, peak};
    temp1 = midpointC - midpointA;
    vec3 normal2 = normalize(cross(temp1, temp2));

    if (distance(centerOf(base2), centerOfTetrahedron) > distance(centerOf(base2) + normal2 / 100, centerOfTetrahedron))
        normal2 *= -1;

    vec3 peak2 = normal2 * height / 2 + centerOf(base2);

    vector<vec3> base3 = {midpointB, midpointC, peak};
    temp1 = midpointC - midpointB;
    temp2 = peak - midpointB;
    vec3 normal3 = normalize(cross(temp1, temp2));

    if (distance(centerOf(base3), centerOfTetrahedron) > distance(centerOf(base3) + normal3 / 100, centerOfTetrahedron))
        normal3 *= -1;

    vec3 peak3 = normal3 * height / 2 + centerOf(base3);

    // Calculate the normal of the base
    vec3 baseNormal = normalize(peak - centerOfBase);

    vector<vec3> base4 = {base[0], midpointA, midpointB};
    vec3 peak4 = baseNormal * height / 2 + centerOf(base4);

    vector<vec3> base5 = {base[1], midpointA, midpointC};
    vec3 peak5 = baseNormal * height / 2 + centerOf(base5);

    vector<vec3> base6 = {base[2], midpointB, midpointC};
    vec3 peak6 = baseNormal * height / 2 + centerOf(base6);

    // Now we add the faces that are not the base of the new tetrahedron to the mesh. We don't add the base because the parent's face is already being drawn.
    mesh.addVertex(midpointA);
    mesh.addVertex(midpointB);
    mesh.addVertex(peak);
    
    mesh.addVertex(midpointA);
    mesh.addVertex(midpointC);
    mesh.addVertex(peak);

    mesh.addVertex(midpointB);
    mesh.addVertex(midpointC);
    mesh.addVertex(peak);

    generateTetrahedron(base1, peak1, n - 1);
    generateTetrahedron(base2, peak2, n - 1);
    generateTetrahedron(base3, peak3, n - 1);
    if (n != 3 && extrudeAllFaces) { // We don't want to add the tetrahedrons from the fake base that isn't actually drawn.
        generateTetrahedron(base4, peak4, n - 1);
        generateTetrahedron(base5, peak5, n - 1);
        generateTetrahedron(base6, peak6, n - 1);
    }
}

void Fractal3D::reset() {
    mesh.clear();  
}

map<string, float> Fractal3D::getDefaultConfig() {
    return map<string, float> {
        {"n", 3},
        {"scale", 100}        
    };
}

void Fractal3D::toggleDetail() {
    extrudeAllFaces = !extrudeAllFaces;
}
