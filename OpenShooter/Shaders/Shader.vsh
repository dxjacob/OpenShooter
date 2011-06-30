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
varying vec3 Normal;
varying vec3 CameraView;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

uniform vec3 CameraPosition;

const vec3 LightDirection = vec3(0.707, 0, -0.707);
const vec3 LightColor = vec3(1, 1, 1);

void main()
{
    // position
    vec4 worldPosition = Model * position;
    vec4 viewPosition = View * worldPosition;
    gl_Position = Projection * viewPosition;
    
    CameraView = normalize(CameraPosition - viewPosition.xyz);
    Normal = mat3(Model) * normal;
    TextureCoord = textureCoord;
}
