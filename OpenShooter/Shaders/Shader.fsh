//
//  Shader.fsh
//  OpenShooter
//
//  Created by Jacob Beaudoin on 6/25/11.
//  Copyright 2011 SMT. All rights reserved.
//

varying lowp vec4 Color;
varying lowp vec2 TextureCoord;

void main()
{
    gl_FragColor = vec4(TextureCoord.x, TextureCoord.y, 0, 1);
}
