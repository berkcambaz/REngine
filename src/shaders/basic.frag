#version 330 core

layout (location = 0) out vec4 color;

in DATA {
	vec4 position;
	vec4 color;
} fs_in;

uniform vec4 obj_color;
uniform vec2 light_pos;

void main() {
	float intensity = 1.0f / length(fs_in.position.xy - light_pos); 
	//color = obj_color * intensity;
	color = fs_in.color * intensity;
}