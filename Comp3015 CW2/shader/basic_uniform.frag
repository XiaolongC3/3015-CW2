#version 460
out vec4 FragColor;

in vec3 Normal;
in vec2 Texcoord;

uniform sampler2D myTexture;

void main() {
	vec3 color = texture(myTexture, Texcoord).rgb;
	FragColor = vec4(color, 1.f);
}