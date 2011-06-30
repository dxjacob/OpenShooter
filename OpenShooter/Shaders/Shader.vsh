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

varying vec4 Color;
varying vec2 TextureCoord;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

void main()
{
    gl_Position = Projection * View * Model * position;
    Color = color;
    TextureCoord = textureCoord;
}
