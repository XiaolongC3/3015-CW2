#version 460

layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexcoord;

out vec3 Normal;
out vec2 Texcoord;
out vec4 FragPosLightSpace;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 lightSpaceMatrix;

void main() {
	gl_Position = projection * view * model * vec4(aPosition, 1.0f);
	
    Normal = aNormal;
    Texcoord = aTexcoord;

	FragPos = vec3(model * vec4(aPosition, 1.0));
	FragPosLightSpace = lightSpaceMatrix * vec4(FragPos, 1.0);
}