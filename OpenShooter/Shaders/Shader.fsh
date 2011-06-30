//
//  Shader.fsh
//  OpenShooter
//
//  Created by Jacob Beaudoin on 6/25/11.
//  Copyright 2011 SMT. All rights reserved.
//

varying lowp vec3 Color;
varying lowp vec2 TextureCoord;
varying highp vec3 Normal;

uniform sampler2D TextureSampler;

const lowp vec3 LightDirection = vec3(0.707, 0, -0.707);
const lowp vec3 LightColor = vec3(1, 1, 1);

void main()
{
    highp vec3 diffuse = LightColor * dot(LightDirection, normalize(Normal));
    highp vec3 textureColor = texture2D(TextureSampler, TextureCoord).xyz;
    
    highp vec3 frag = diffuse * textureColor;
    gl_FragColor = vec4(frag,1);
}
