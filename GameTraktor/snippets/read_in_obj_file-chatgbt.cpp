#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

struct Vertex {
    float x, y, z;
};

struct Face {
    int v1, v2, v3;
};

std::vector<Vertex> vertices;
std::vector<Face> faces;

void display(GLFWwindow* window) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0,  // eye position
        0.0, 0.0, 0.0,  // center position
        0.0, 1.0, 0.0); // up direction

    // Set the color to white
    glColor3f(1.0, 1.0, 1.0);

    // Draw the vertices and faces
    glBegin(GL_TRIANGLES);
    for (const Face& f : faces) {
        Vertex v1 = vertices[f.v1 - 1];
        Vertex v2 = vertices[f.v2 - 1];
        Vertex v3 = vertices[f.v3 - 1];
        glVertex3f(v1.x, v1.y, v1.z);
        glVertex3f(v2.x, v2.y, v2.z);
        glVertex3f(v3.x, v3.y, v3.z);
    }
    glEnd();

    glfwSwapBuffers(window);
}

int main(int argc, char** argv) {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return -1;
    }

    // Create a window
    GLFWwindow* window = glfwCreateWindow(400, 400, "OBJ Viewer", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW!" << std::endl;
        return -1;
    }

    // Read in the OBJ file
    std::ifstream objFile("file.obj");
    std::string line;
    while (std::getline(objFile, line)) {
        if (line[0] == 'v') {
            // This line is a vertex
            Vertex vertex;
            sscanf(line.c_str(), "v %f %f %f", &vertex.x, &vertex.y, &vertex.z);
            vertices.push_back(vertex);
        }
        else if (line[0] == 'f') {
            // This line is a face
            Face face;
            sscanf(line.c_str(), "f %d %d %d", &face.v1, &face.v2, &face.v3);
            faces.push_back(face);
        }
    }

    // Set the background color to black
    glClearColor(0.0, 0.0, 0.0, 0.0);

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    // Enter the main loop
    while (!glfwWindowShouldClose(window)) {
        display(window);
        glfwPollEvents();
    }

    // Clean up
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}