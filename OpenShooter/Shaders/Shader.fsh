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

const lowp float SpecularPower = 1.0;
const highp float SpecularHardness = 4.0;
const lowp vec3 SpecularColor = vec3(1,1,1);

void main()
{
    lowp vec3 normal = normalize(Normal);
    lowp vec3 cameraDir = normalize(CameraView);
    
    // half lambert
    highp vec3 diffuse = LightColor * dot(LightDirection, normal);
    diffuse = diffuse * 0.5 + 0.5;
    
    // rim
    highp float rim = dot(cameraDir, normal);
    rim = pow(1.0 - abs(rim), 3.0);
    highp vec3 rimColor = rim * RimLightColor;
    
    // specular
    highp float specularAmount = dot(normal, reflect(LightDirection, cameraDir));
    specularAmount = pow(max(specularAmount, 0.0), SpecularHardness);
    highp vec3 specular = SpecularPower * SpecularColor * specularAmount;
    
    // texture
    highp vec3 textureColor = texture2D(TextureSampler, TextureCoord).xyz;
    
    // final
    highp vec3 frag = diffuse * textureColor + rimColor + specular;
    gl_FragColor = vec4(frag.xyz,1);
}
