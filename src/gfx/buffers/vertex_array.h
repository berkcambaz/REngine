#pragma once

#include "buffer.h"

#include <glad/glad.h>

#include <vector>

namespace ren {

	namespace gfx {

		class VertexArray {
		private:
			GLuint m_ArrayID;
			std::vector<Buffer*> m_Buffers;
		public:
			VertexArray();
			~VertexArray();

			void addBuffer(Buffer* buffer, GLuint index);

			void bind() const;
			void unbind() const;
		};

	}

}