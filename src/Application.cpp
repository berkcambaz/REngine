#include "gfx/window.h"
#include "gfx/shader.h"

#include "maths/maths.h"

#include "gfx/buffers/buffer.h"
#include "gfx/buffers/index_buffer.h"
#include "gfx/buffers/vertex_array.h"

#include "gfx/renderer2d.h"
#include "gfx/simple_2drenderer.h"

int main() {
	using namespace ren;
	using namespace gfx;
	using namespace maths;

	Window window(960, 540, "RENgine Test");

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();

	shader.setUniformMat4("projection", ortho);
	shader.setUniform4f("obj_color", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	Renderable2D sprite(maths::vec3(5, 5, 0), maths::vec2(4, 4), maths::vec4(1, 0, 1, 1), shader);
	Renderable2D sprite1(maths::vec3(7, 1, 0), maths::vec2(2, 3), maths::vec4(0.2f, 0, 1, 1), shader);
	Simple2DRenderer renderer;

	while (!window.closed()) {
		window.clear();

		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)x * 16.0f / 960.0f, 9.0f - (float)y * 9.0f / 540.0f));

		renderer.submit(&sprite);
		renderer.submit(&sprite1);
		renderer.flush();

		window.update();
	}

	return 0;
}