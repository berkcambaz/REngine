#version 330 core

layout (location = 0) in vec4 position;	
layout (location = 1) in vec4 color;	

uniform mat4 projection;
uniform mat4 view = mat4(1.0f);
uniform mat4 model = mat4(1.0f);

out DATA {
	vec4 position;
	vec4 color;
} vs_out;

void main() {
	vs_out.color = color;
	vs_out.position = model * position;
	gl_Position = projection * view * model * position;	
}