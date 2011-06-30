//
//  Shader.vsh
//  OpenShooter
//
//  Created by Jacob Beaudoin on 6/25/11.
//  Copyright 2011 SMT. All rights reserved.
//

attribute vec4 position;
attribute vec4 color;

varying vec4 Color;

uniform mat4 View;
uniform mat4 Projection;

void main()
{
    gl_Position = Projection * View * position;
    Color = color;
}
