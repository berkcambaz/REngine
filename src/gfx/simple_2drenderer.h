#pragma once

#include "renderer2d.h"

#include <deque>

namespace ren {

	namespace gfx {

		class Simple2DRenderer : public Renderer2D {
		private:
			std::deque<const Renderable2D*> m_RenderQueue;
		public:
			void submit(const Renderable2D* renderable) override;
			void flush() override;
		};

	}

}