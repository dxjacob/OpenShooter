//
//  Shader.vsh
//  OpenShooter
//
//  Created by Jacob Beaudoin on 6/25/11.
//  Copyright 2011 SMT. All rights reserved.
//

attribute vec4 position;
attribute vec4 color;
attribute vec2 textureCoord;
attribute vec3 normal;

varying vec3 Color;
varying vec2 TextureCoord;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

const vec3 LightDirection = vec3(0.707, 0, -0.707);
const vec3 LightColor = vec3(1, 1, 1);

void main()
{
    gl_Position = Projection * View * Model * position;
    
    // transform normal
    vec4 n = Model * vec4(normal,0);
    
    // N dot L
    float diffuse = dot(n.xyz, LightDirection);
    
    Color = LightColor * diffuse;
    TextureCoord = textureCoord;
}
