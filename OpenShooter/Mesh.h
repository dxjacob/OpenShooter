#pragma once
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

struct Vector
{
    GLfloat x, y, z;
    Vector() {};
    Vector(GLfloat x, GLfloat y, GLfloat z)
    : x(x), y(y), z(z)
    {}
};

struct Color
{
    GLubyte r, g, b, a;
    Color() {};
    Color(GLubyte r, GLubyte g, GLubyte b, GLubyte a)
    : r(r), g(g), b(b), a(a)
    {}
};

struct Vertex
{
    Vector position;
    Color color;
    
    Vertex() {};
    Vertex(Vector position, Color color)
    : position(position), color(color)
    {}
};

class Mesh
{
public:
    Mesh();
    ~Mesh();
    
    void Draw(int vertexAttribute, int colorAttribute);
    
private:
    GLuint bufferId_;
    
    int vertexCount_;
    int colorCount_;
};