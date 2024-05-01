#version 460

layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexcoord;

out vec3 Normal;
out vec2 Texcoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main() {
	gl_Position = projection * view * model * vec4(aPosition, 1.0f);
	
    Normal = aNormal;
    Texcoord = aTexcoord;
}