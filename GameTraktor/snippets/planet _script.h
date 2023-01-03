#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

#ifndef MODEL_H
#define MODEL_H

#define M_PI 3.14159

#include <vector>

struct Vertex {
    float x, y, z;
};

struct Face {
    int v1, v2, v3;
};

struct Model {
    std::vector<Vertex> vertices;
    std::vector<Face> faces;
};

#endif

// A structure representing a vertex in 3D space
struct Vertex {
    float x, y, z;
};

// A structure representing a face of a 3D model
struct Face {
    int v1, v2, v3;
};

// A structure representing a 3D model
struct Model {
    std::vector<Vertex> vertices;
    std::vector<Face> faces;
};

// Generate a random float between min and max
float randFloat(float min, float max) {
    return min + (max - min) * rand() / RAND_MAX;
}

// Generate a random vertex on the surface of a sphere
Vertex randVertex(float radius) {
    float theta = randFloat(0.0, 2 * M_PI);
    float phi = randFloat(-M_PI / 2, M_PI / 2);
    Vertex v;
    v.x = radius * sin(phi) * cos(theta);
    v.y = radius * sin(phi) * sin(theta);
    v.z = radius * cos(phi);
    return v;
}

// Generate a 3D model of a planet with random biomes
Model generatePlanet() {
    Model planet;

    // Generate a random number of vertices
    int numVertices = rand() % 100 + 50;
    for (int i = 0; i < numVertices; i++) {
        planet.vertices.push_back(randVertex(1.0));
    }

    // Generate random faces connecting the vertices
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            for (int k = j + 1; k < numVertices; k++)
            {
                // Generate a random face with vertices i, j, and k
                Face f;
                f.v1 = i;
                f.v2 = j;
                f.v3 = k;
                planet.faces.push_back(f);
            }
        }
    }

    return planet;
}

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random planet
    Model planet = generatePlanet();

    // Print the number of vertices and faces in the planet
    std::cout << "Planet with " << planet.vertices.size() << " vertices and "
        << planet.faces.size() << " faces" << std::endl;

    return 0;
}

//void exportToBlender(const Model& model, const std::string& filename) {
//    std::ofstream out(filename);
//
//    // Write the vertices to the file
//    for (const Vertex& v : model.vertices) {
//        out << "v " << v.x << " " << v.y << " " << v.z << std::endl;
//    }
//
//    // Write the faces to the file
//    for (const Face& f : model.faces) {
//        out << "f " << f.v1 + 1 << " " << f.v2 + 1 << " " << f.v3 + 1 << std::endl;
//    }
//
//    out.close();
//}
//Model planet = generatePlanet();
//
//exportToBlender(planet, "planet.obj");
