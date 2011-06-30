#pragma once
#include "Vertex.h"

class Mesh
{
public:
    Mesh(GLuint bufferId, int vertexCount)
    : bufferId_(bufferId), vertexCount_(vertexCount)
    {}
    
    ~Mesh();
    
    void Draw(int vertexAttribute, int colorAttribute, int textureAttrib, int normalAttrib);
    
    static Mesh* CreateCylinder(int sides, float radius, float height);
    
private:
    GLuint bufferId_;
    int vertexCount_;
};