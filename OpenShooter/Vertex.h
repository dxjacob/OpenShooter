#pragma once
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#import "vectormath/vectormath_aos.h"
using namespace Vectormath::Aos;

struct Color
{
    GLubyte r, g, b, a;
    Color() {};
    Color(GLubyte r, GLubyte g, GLubyte b, GLubyte a)
    : r(r), g(g), b(b), a(a)
    {}
};

struct TextureCoord
{
    float u, v;
    TextureCoord() {}
    TextureCoord(float u, float v)
    : u(u), v(v)
    {}
};

struct Vertex
{
    Vector3 position;
    Color color;
    TextureCoord textureCoord;
    
    Vertex() {};
    Vertex(Vector3 position, Color color, TextureCoord textureCoord)
    : position(position), color(color), textureCoord(textureCoord)
    {}
};