#include "gfx/window.h"
#include "gfx/shader.h"
#include "maths/maths.h"

#include "gfx/buffers/buffer.h"
#include "gfx/buffers/index_buffer.h"
#include "gfx/buffers/vertex_array.h"

int main() {
	using namespace ren;
	using namespace gfx;
	using namespace maths;

	Window window(960, 540, "RENgine Test");

#if 0
	GLfloat vertices[] = {
		4, 3, 0,
		12, 3, 0,
		4, 6, 0,
		4, 6, 0,
		12, 6, 0,
		12, 3, 0
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);
	glEnableVertexAttribArray(0);
#else 
	GLfloat vertices[] = {
		4, 6, 0,
		4, 3, 0,
		12, 3, 0,
		12, 6, 0
	};

	GLushort indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	GLfloat colorsA[] = {
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1
	};

	GLfloat colorsB[] = {
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1
	};

	VertexArray sprite1, sprite2;
	IndexBuffer ibo(indices, 6);

	sprite1.addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite1.addBuffer(new Buffer(colorsA, 4 * 4, 4), 1);
	sprite2.addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite2.addBuffer(new Buffer(colorsB, 4 * 4, 4), 1);
#endif

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	shader.setUniformMat4("projection", ortho);

	//shader.setUniformMat4("model", mat4::translation(vec3(2.0f, 1.5f, 0.0f)));
	//shader.setUniformMat4("model", mat4::rotation(45.0f, vec3(0.0f, 0.0f, 1.0f)));
	//shader.setUniformMat4("model", mat4::scale(vec3(0.5f, 0.5f, 1.0f)));

	shader.setUniform4f("obj_color", vec4(0.2f, 0.3f, 0.8f, 1.0f));
	//shader.setUniform2f("light_pos", vec2(8.0f, 4.5f));

	float angle = 0.0f;

	while (!window.closed()) {
		double x, y;
		window.getMousePosition(x, y);

		if (window.isKeyPressed(GLFW_KEY_A))
			angle -= 0.005f;
		if (window.isKeyPressed(GLFW_KEY_D))
			angle += 0.005f;

		//shader.setUniformMat4("model", mat4::rotation(angle, vec3(0.0f, 0.0f, 1.0f)) * mat4::translation(vec3(-4.0f, -3.0f, 0.0f)));
		shader.setUniform2f("light_pos", vec2(x * 16.0f / 960.0f, 9.0f - y * 9.0f / 540.0f));

		window.clear();
#if 0
		glDrawArrays(GL_TRIANGLES, 0, 6);
#else
		sprite1.bind();
		ibo.bind();
		shader.setUniformMat4("model", mat4::translation(vec3(0.0f, 0.0f, 0.0f)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, nullptr);
		sprite1.unbind();
		ibo.unbind();

		sprite2.bind();
		ibo.bind();
		shader.setUniformMat4("model", mat4::translation(vec3(-4.0f, -3.0f, 0.0f)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, nullptr);
		sprite2.unbind();
		ibo.unbind();
#endif
		window.update();
	}

	return 0;
}