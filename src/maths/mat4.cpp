#include "mat4.h"

namespace ren {

	namespace maths {

		mat4::mat4() {}

		mat4::mat4(float diagonal) {
			elements[0 + 0 * 4] = diagonal;
			elements[1 + 1 * 4] = diagonal;
			elements[2 + 2 * 4] = diagonal;
			elements[3 + 3 * 4] = diagonal;
		}

		mat4::mat4(const mat4& matrix) {
			for (int i = 0; i < 16; i++)
				elements[i] = matrix.elements[i];
		}

		mat4 mat4::identity() {
			return mat4(1.0f);
		}

		mat4 mat4::multiply(const mat4& other) const {
			mat4 matrix;
			for (int y = 0; y < 4; y++) {
				for (int x = 0; x < 4; x++) {
					float sum = 0.0f;
					for (int e = 0; e < 4; e++) {
						sum += elements[x + (e * 4)] * other.elements[e + (y * 4)];
					}
					matrix.elements[x + (y * 4)] = sum;
				}
			}
			return matrix;
		}

		mat4 mat4::orthographic(float left, float right, float bottom, float top, float far, float near) {
			mat4 matrix;

			//matrix.elements[0 + 0 * 4] = 2 / (right - left);
			//matrix.elements[1 + 1 * 4] = 2 / (top - bottom);
			//matrix.elements[2 + 2 * 4] = 2 / (near - far);
			matrix.elements[3 + 3 * 4] = 1.0f;

			matrix.elements[0 + 0 * 4] = 2 / (right - left);
			matrix.elements[1 + 1 * 4] = 2 / (top - bottom);
			matrix.elements[2 + 2 * 4] = -2 / (far - near);

			//matrix.elements[0 + 3 * 4] = (left + right) / (left - right);
			//matrix.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
			//matrix.elements[2 + 3 * 4] = (far + near) / (far - near);

			matrix.elements[0 + 3 * 4] = (right + left) / (left - right);
			matrix.elements[1 + 3 * 4] = (top + bottom) / (bottom - top);
			matrix.elements[2 + 3 * 4] = (far + near) / (near - far);

			return matrix;
		}

		mat4 mat4::perspective(float fov, float aspectRatio, float far, float near) {
			mat4 matrix;

			float a = 1.0f / tan(toRadians(fov / 2.0f));
			float b = a / aspectRatio;

			float c = (far + near) / (near - far);
			float d = (2.0f * far * near) / (near - far);

			matrix.elements[0 + 0 * 4] = b;
			matrix.elements[1 + 1 * 4] = a;
			matrix.elements[2 + 2 * 4] = c;

			matrix.elements[3 + 2 * 4] = -1.0f;
			matrix.elements[2 + 3 * 4] = d;

			return matrix;
		}

		mat4 mat4::translation(const vec3& translation) {
			mat4 matrix(1.0f);

			matrix.elements[0 + 3 * 4] = translation.x;
			matrix.elements[1 + 3 * 4] = translation.y;
			matrix.elements[2 + 3 * 4] = translation.z;

			return matrix;
		}

		mat4 mat4::rotation(float angle, const vec3& axis) {
			mat4 matrix;

			float r = toRadians(angle);
			float c = cos(r);
			float s = sin(r);
			float omc = 1.0f - c;

			matrix.elements[0 + 0 * 4] = axis.x * axis.x * omc + c;
			matrix.elements[0 + 1 * 4] = axis.y * axis.x * omc + axis.z * s;
			matrix.elements[0 + 2 * 4] = axis.z * axis.x * omc - axis.y * s;

			matrix.elements[1 + 0 * 4] = axis.x * axis.y * omc - axis.z * s;
			matrix.elements[1 + 1 * 4] = axis.y * axis.y * omc + c;
			matrix.elements[1 + 2 * 4] = axis.z * axis.y * omc + axis.x * s;

			matrix.elements[2 + 0 * 4] = axis.x * axis.z * omc + axis.y * s;
			matrix.elements[2 + 1 * 4] = axis.y * axis.z * omc - axis.x * s;
			matrix.elements[2 + 2 * 4] = axis.z * axis.z * omc + c;

			matrix.elements[3 + 3 * 4] = 1.0f;

			return matrix;
		}

		mat4 mat4::scale(const vec3& scale) {
			mat4 matrix;

			matrix.elements[0 + 0 * 4] = scale.x;
			matrix.elements[1 + 1 * 4] = scale.y;
			matrix.elements[2 + 2 * 4] = scale.z;
			matrix.elements[3 + 3 * 4] = 1.0f;

			return matrix;
		}

		mat4 operator*(const mat4& left, const mat4& right) {
			return left.multiply(right);
		}

		void operator*=(mat4& left, const mat4& right) {
			left = left.multiply(right);
		}

	}

}