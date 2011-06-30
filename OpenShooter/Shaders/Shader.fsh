//
//  Shader.fsh
//  OpenShooter
//
//  Created by Jacob Beaudoin on 6/25/11.
//  Copyright 2011 SMT. All rights reserved.
//

varying lowp vec3 Color;
varying lowp vec2 TextureCoord;

uniform sampler2D TextureSampler;

void main()
{
    gl_FragColor = vec4(Color, 1) * texture2D(TextureSampler, TextureCoord);
}
