#pragma once
#include "Vertex.h"

class Texture
{
public:
    Texture();
    ~Texture();
    GLuint GetId() { return id_; }

private:
    GLuint id_;
};