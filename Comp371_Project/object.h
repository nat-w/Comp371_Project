#include "glm/glm.hpp"

class Object {
private:
    glm::vec3 pos;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float shininess;
public:
    Object(){
        pos = glm::vec3(0,0,0);
        ambient = glm::vec3(0,0,0);
        diffuse = glm::vec3(0,0,0);
        specular = glm::vec3(0,0,0);
        shininess = 0.0f;
    }
    
    virtual bool intersect(glm::vec3 rayOrigin, glm::vec3 rayDir) {
        glm::vec3 v1 = pos - rayOrigin; // find better name for v1, what is it?
        glm::vec3 d1 = v1.dot(rayDir); // same as above
        // what does this do
        if (d1 < 0)
            return false;
        return true;
    }
}

class Sphere : Object {
private:
    int radius;
public:
    Circle(glm::vec3 pos, int rad, glm::vec3 amb , glm::vec3 dif, glm::vec3 spec ,float shiny) {
        this.pos = pos;
        radius = rad;
        ambient = amb;
        diffuse = dif;
        specular = spec;
        shininess = shiny;
    }
    
    bool intersect() {
        glm::vec3 v1 = pos - rayOrigin; // find better name for v1, what is it?
        float d1 = v1.dot(rayDir); // same as above
        // test 1 what does it do
        if (d1 < 0)
            return false;
        // test 2 what does it do
        float d2 = v1.dot(v1) - (d1 * d1);
        if (d2 > radius)
            return false;
        return true;
    }
};

class Plane : Object {
private:
    glm::vec3 norms;
public:
    Plane(glm::vec3 norms, glm::vec3 pos, glm::vec3 amb , glm::vec3 dif, glm::vec3 spec ,float shiny) {
        this.pos = pos;
        this.norms = norms;
        ambient = amb;
        diffuse = dif;
        specular = spec;
        shininess = shiny;
    }
};

class Triangle : Object {
private:
public:
    Triangle(glm::vec3 pos, glm::vec3 amb , glm::vec3 dif, glm::vec3 spec ,float shiny) {
        this.pos = pos;
        ambient = amb;
        diffuse = dif;
        specular = spec;
        shininess = shiny;
    }
};
