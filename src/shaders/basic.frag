#version 330 core

layout (location = 0) out vec4 color;

in vec4 pos;

uniform vec4 obj_color;
uniform vec2 light_pos;

void main() {
	float intensity = 1.0f / length(pos.xy - light_pos); 
	color = obj_color * intensity;
}