#include <iostream>
#include <fstream>
#include "glm/glm.hpp"
#include "SceneParser.h"

SceneParser::SceneParser(std::string fileName) {
    std::ifstream in = std::ifstream();
    in.open(fileName);
    
    while (in.good()) {
        std::string header;
        in >> header;
        
        if (header == "camera") {
            std::string divider;
            int px, py, pz, theta, focal_length;
            float aspect_ratio;
            
            in >> divider >> px >> py >> pz;
            in >> divider >> theta;
            in >> divider >> focal_length;
            in >> divider >> aspect_ratio;
        }
        else if (header == "plane") {
            std::string divider;
            int nx, ny, nz, px, py, pz;
            float ax, ay, az, dx, dy, dz, sx, sy, sz, shi;
            
            in >> divider >> nx >> ny >> nz;
            in >> divider >> px >> py >> pz;
            in >> divider >> ax >> ay >> az;
            in >> divider >> dx >> dy >> dz;
            in >> divider >> sx >> sy >> sz;
            in >> divider >> shi;
        }
        else if (header == "sphere") {
            std::string divider;
            int px, py, pz, rad;
            float ax, ay, az, dx, dy, dz, sx, sy, sz, shi;
            
            in >> divider >> px >> py >> pz;
            in >> divider >> rad;
            in >> divider >> ax >> ay >> az;
            in >> divider >> dx >> dy >> dz;
            in >> divider >> sx >> sy >> sz;
            in >> divider >> shi;
        }
        else if (header == "mesh") {
            std::string divider, objFile;
            float ax, ay, az, dx, dy, dz, sx, sy, sz, shi;
            
            in >> divider >> objFile;
            in >> divider >> ax >> ay >> az;
            in >> divider >> dx >> dy >> dz;
            in >> divider >> sx >> sy >> sz;
            in >> divider >> shi;
        }
        else if (header == "light") {
            std::string divider;
            int px, py, pz;
            float ax, ay, az, dx, dy, dz, sx, sy, sz;
            
            in >> divider >> px >> py >> pz;
            in >> divider >> ax >> ay >> az;
            in >> divider >> dx >> dy >> dz;
            in >> divider >> sx >> sy >> sz;
        }
    }
};
