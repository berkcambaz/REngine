#include "shader.h"

namespace ren {

	namespace gfx {

		Shader::Shader(const char* vertPath, const char* fragPath) : m_VertPath(vertPath), m_FragPath(fragPath) {
			m_ShaderID = load();
		}

		Shader::~Shader() {
			glDeleteProgram(m_ShaderID);
		}

		void Shader::setUniform1i(const GLchar* name, int value) {
			glUniform1i(getUniformLocation(name), value);
		}

		void Shader::setUniform1f(const GLchar* name, float value) {
			glUniform1f(getUniformLocation(name), value);
		}

		void Shader::setUniform2f(const GLchar* name, const maths::vec2& value) {
			glUniform2f(getUniformLocation(name), value.x, value.y);
		}

		void Shader::setUniform3f(const GLchar* name, const maths::vec3& value) {
			glUniform3f(getUniformLocation(name), value.x, value.y, value.z);
		}

		void Shader::setUniform4f(const GLchar* name, const maths::vec4& value) {
			glUniform4f(getUniformLocation(name), value.x, value.y, value.z, value.w);
		}

		void Shader::setUniformMat4(const GLchar* name, const maths::mat4& value) {
			glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, value.elements);
		}

		void Shader::enable() const {
			glUseProgram(m_ShaderID);
		}

		void Shader::disable() const {
			glUseProgram(0);
		}

		GLuint Shader::load() {
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertSourceString = util::read_file(m_VertPath);
			std::string fragSourceString = util::read_file(m_FragPath);

			const char* vertSource = vertSourceString.c_str();
			const char* fragSource = fragSourceString.c_str();

			GLint success;

			glShaderSource(vertex, 1, &vertSource, nullptr);
			glCompileShader(vertex);

			glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
			if (!success) {
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				char* infoLog = new char[length + 1]{};
				glGetShaderInfoLog(vertex, length, &length, infoLog);
				std::cout << "Failed to compile vertex shader!" << std::endl << infoLog << std::endl;
				delete[] infoLog;
				glDeleteShader(vertex);
				return 0;
			}

			glShaderSource(fragment, 1, &fragSource, nullptr);
			glCompileShader(fragment);

			glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
			if (!success) {
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				char* infoLog = new char[length + 1]{};
				glGetShaderInfoLog(fragment, length, &length, infoLog);
				std::cout << "Failed to compile fragment shader!" << std::endl << infoLog << std::endl;
				delete[] infoLog;
				glDeleteShader(fragment);
				return 0;
			}

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return program;
		}

		GLuint Shader::getUniformLocation(const GLchar* name) {
			return glGetUniformLocation(m_ShaderID, name);
		}

	}

}