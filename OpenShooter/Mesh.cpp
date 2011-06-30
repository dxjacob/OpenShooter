#include "Mesh.h"
#include "math.h"
#include "stddef.h"
#include <vector>
using namespace std;

#define toRadians(x) (x*M_PI/180.0)

Mesh* Mesh::CreateCylinder(int sides, float radius, float height)
{
    vector<Vertex> vertices;
    for (int i = 0; i <= sides; ++i)
    {
        // position
        float angle = toRadians(360.0 * i / (float)sides);
        float x = radius * cosf(angle);
        float z = radius * sinf(angle);
        
        // color
        GLubyte red = 255 * (i / (float)sides);
        Color color(red, 0, 0, 255);
        
        // texture coord
        float u =  i / (float)sides;
        
        // normal
        Vector3 normal(cosf(angle), 0, sinf(angle));
        
        vertices.push_back( Vertex( Vector3(x, -height/2, z), color, TextureCoord(u, 0), normal ) );
        vertices.push_back( Vertex( Vector3(x, height/2, z), color, TextureCoord(u, 1), normal ) );
    }  
    
    GLuint bufferId;
    glGenBuffers(1, &bufferId);
    glBindBuffer(GL_ARRAY_BUFFER, bufferId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
    
    return new Mesh(bufferId, vertices.size());
}

void Mesh::Draw(int positionAttrib, int colorAttrib, int textureAttrib, int normalAttrib)
{
    glBindBuffer(GL_ARRAY_BUFFER, bufferId_);
    
    glVertexAttribPointer(positionAttrib, 3, GL_FLOAT, 0, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
    glEnableVertexAttribArray(positionAttrib);
    
    glVertexAttribPointer(colorAttrib, 4, GL_UNSIGNED_BYTE, 1, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
    glEnableVertexAttribArray(colorAttrib);
    
    glVertexAttribPointer(textureAttrib, 2, GL_FLOAT, 0, sizeof(Vertex), (GLvoid*)offsetof(Vertex, textureCoord));
    glEnableVertexAttribArray(textureAttrib);
    
    glVertexAttribPointer(normalAttrib, 3, GL_FLOAT, 0, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(normalAttrib);
    
    glDrawArrays(GL_TRIANGLE_STRIP, 0, vertexCount_);
}

Mesh::~Mesh()
{
    glDeleteBuffers(1, &bufferId_);
}