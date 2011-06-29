#include "Mesh.h"
#include "math.h"
#include <iostream>
using namespace std;

#define toRadians(x) (x*M_PI/180.0)

Mesh::Mesh()
{
    int sides = 9;
    float radius = 0.2;
    float height = 0.5;
    
    vertexCount_ = 2 * (sides + 1);
    vertices_ = new Vertex[vertexCount_];
    colors_ = new Color[vertexCount_];
    
    Vertex *v = vertices_;
    Color *c = colors_;
    for (int i = 0; i <= sides; ++i)
    {
        // position
        float angle = toRadians(360.0 * i / (float)sides);
        float x = radius * cosf(angle);
        float z = radius * sinf(angle);
        
        cout << "angle: " << angle << endl;
        
        *v++ = Vertex(x, -height/2, z);
        *v++ = Vertex(x, height/2, z);
        
        // color
        GLubyte red = 255 * (i / (float)sides);
        Color color(red, 0, 0, 255);
        
        cout << "color: " << (int)red << endl;
        
        *c++ = color;
        *c++ = color;
    }  
}

void Mesh::Draw(int positionAttrib, int colorAttrib)
{
    glVertexAttribPointer(positionAttrib, 3, GL_FLOAT, 0, 0, vertices_);
    glEnableVertexAttribArray(positionAttrib);
    glVertexAttribPointer(colorAttrib, 4, GL_UNSIGNED_BYTE, 1, 0, colors_);
    glEnableVertexAttribArray(colorAttrib);
    
    glDrawArrays(GL_TRIANGLE_STRIP, 0, vertexCount_);
}

Mesh::~Mesh()
{
    delete vertices_;
    delete colors_;
}