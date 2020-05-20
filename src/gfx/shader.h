#pragma once

#include "../utils/file_utils.h"
#include "../maths/maths.h"

#include <glad\glad.h>

#include <iostream>

namespace ren {

	namespace gfx {

		class Shader {
		private:
			GLuint m_ShaderID;
			const char* m_VertPath;
			const char* m_FragPath;
		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();

			void setUniform1i(const GLchar* name, int value);
			void setUniform1f(const GLchar* name, float value);
			void setUniform2f(const GLchar* name, const maths::vec2& value);
			void setUniform3f(const GLchar* name, const maths::vec3& value);
			void setUniform4f(const GLchar* name, const maths::vec4& value);
			void setUniformMat4(const GLchar* name, const maths::mat4& value);

			void enable() const;
			void disable() const;
		private:
			GLuint load();
			GLuint getUniformLocation(const GLchar* name);
		};

	}

}