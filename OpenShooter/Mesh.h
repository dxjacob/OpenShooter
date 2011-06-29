#pragma once
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

struct Vertex
{
    GLfloat x, y, z;
    
    Vertex() {};
    Vertex(GLfloat x, GLfloat y, GLfloat z)
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

class Mesh
{
public:
    Mesh();
    ~Mesh();
    
    void Draw(int vertexAttribute, int colorAttribute);
    
private:
    Vertex *vertices_;
    Color *colors_;
    
    int vertexCount_;
    int colorCount_;
};