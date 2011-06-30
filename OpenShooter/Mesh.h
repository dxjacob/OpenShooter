#pragma once
#include "Vertex.h"

class Mesh
{
public:
    Mesh();
    ~Mesh();
    
    void Draw(int vertexAttribute, int colorAttribute, int textureAttrib);
    
private:
    GLuint bufferId_;
    
    int vertexCount_;
    int colorCount_;
};