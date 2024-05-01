#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D scene;
uniform sampler2D bloomBlur;
uniform bool useBlur;

void main()
{            
    vec3 hdrColor = texture(scene, TexCoords).rgb;      
    vec3 bloomColor = texture(bloomBlur, TexCoords).rgb;
    vec3 result;
    if(useBlur){
        result = bloomColor;
    }
    else {
        result = hdrColor;
    }

    FragColor = vec4(result, 1.0);
}