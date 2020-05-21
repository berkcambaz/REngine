#pragma once

#include <glad/glad.h>
#include "../maths/maths.h"
#include "renderable2d.h"

namespace ren {

	namespace gfx {

		class Renderer2D {
		public:
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void flush() = 0;
		};

	}

}