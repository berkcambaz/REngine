#pragma once

#include "maths.h"
#include "math_funcs.h"

namespace ren {

	namespace maths {

		struct mat4 {
			union {
				float elements[16]{};
				vec4 columns[4];
			};

			mat4();
			mat4(float diagonal);
			mat4(const mat4& matrix);

			static mat4 identity();

			mat4 multiply(const mat4& other) const;

			static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
			static mat4 perspective(float fov, float aspectRatio, float near, float far);

			static mat4 translation(const vec3& translation);
			static mat4 rotation(float angle, const vec3& axis);
			static mat4 scale(const vec3& scale);
		};

		mat4 operator*(const mat4& left, const mat4& right);
		void operator*=(mat4& left, const mat4& right);

	}

}


