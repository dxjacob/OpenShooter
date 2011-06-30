#pragma once
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

class Texture
{
public:
    Texture();
    ~Texture();
    GLuint GetId() { return id_; }

private:
    GLuint id_;
};