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
varying highp vec3 CameraView;

uniform sampler2D TextureSampler;

const lowp vec3 LightDirection = vec3(0.707, 0, -0.707);
const lowp vec3 LightColor = vec3(1, 1, 1);
const lowp vec3 RimLightColor = vec3(0.15, 0.3, 0.6);

void main()
{
    // half lambert
    highp vec3 diffuse = LightColor * dot(LightDirection, normalize(Normal));
    diffuse = diffuse * 0.5 + 0.5;
    
    // rim
    highp float rim = dot(normalize(CameraView), normalize(Normal));
    rim = pow(1.0 - abs(rim), 3.0);
    highp vec3 rimColor = rim * RimLightColor;
    
    // texture
    highp vec3 textureColor = texture2D(TextureSampler, TextureCoord).xyz;
    
    // final
    highp vec3 frag = diffuse * textureColor + rimColor;
    gl_FragColor = vec4(frag.xyz,1);
}
