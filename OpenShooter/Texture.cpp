#include "Texture.h"
#include <vector>
using namespace std;

Texture::Texture()
{
    vector<Color> colors;
    colors.push_back(Color(255,0,0,255));
    colors.push_back(Color(0,255,0,255));
    colors.push_back(Color(0,0,255,255));
    colors.push_back(Color(255,255,255,255));

    // create texture
    glGenTextures(1, &id_);
    glBindTexture(GL_TEXTURE_2D, id_);
    
    // texture paramters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    // load data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &colors[0]);  
}

Texture::~Texture()
{
    glDeleteTextures(1, &id_);
}