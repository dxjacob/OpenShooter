#include "Mesh.h"
#include "math.h"
#include "stddef.h"

#define toRadians(x) (x*M_PI/180.0)

Mesh::Mesh()
{
    int sides = 9;
    float radius = 0.2;
    float height = 0.5;
    
    vertexCount_ = 2 * (sides + 1);
    Vertex *vertices = new Vertex[vertexCount_];
    
    Vertex *v = vertices;
    for (int i = 0; i <= sides; ++i)
    {
        // position
        float angle = toRadians(360.0 * i / (float)sides);
        float x = radius * cosf(angle);
        float z = radius * sinf(angle);
        
        // color
        GLubyte red = 255 * (i / (float)sides);
        Color color(red, 0, 0, 255);
        
        *v++ = Vertex( Vector(x, -height/2, z), color);
        *v++ = Vertex( Vector(x, height/2, z), color);
    }  
    
    glGenBuffers(1, &bufferId_);
    glBindBuffer(GL_ARRAY_BUFFER, bufferId_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertexCount_, vertices, GL_STATIC_DRAW);
    
}

void Mesh::Draw(int positionAttrib, int colorAttrib)
{
    glBindBuffer(GL_ARRAY_BUFFER, bufferId_);
    
    glVertexAttribPointer(positionAttrib, 3, GL_FLOAT, 0, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
    glEnableVertexAttribArray(positionAttrib);
    glVertexAttribPointer(colorAttrib, 4, GL_UNSIGNED_BYTE, 1, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
    glEnableVertexAttribArray(colorAttrib);
    
    
    glDrawArrays(GL_TRIANGLE_STRIP, 0, vertexCount_);
}

Mesh::~Mesh()
{
    glDeleteBuffers(1, &bufferId_);
}