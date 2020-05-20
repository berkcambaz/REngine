#include "vec4.h"

namespace ren {

	namespace maths {

		vec4::vec4() {
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			w = 0.0f;
		}

		vec4::vec4(const float xyzw) {
			x = xyzw;
			y = xyzw;
			z = xyzw;
			w = xyzw;
		}

		vec4::vec4(const vec4& vector) : x(vector.x), y(vector.y), z(vector.z), w(vector.w) {}

		vec4::vec4(float x, float y, float z, float w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		vec4 vec4::add(float scalar) const {
			return { x + scalar, y + scalar, z + scalar, w + scalar };
		}

		vec4 vec4::subtract(float scalar) const {
			return { x - scalar, y - scalar, z - scalar, w + scalar };
		}

		vec4 vec4::multiply(float scalar) const {
			return { x * scalar, y * scalar, z * scalar, w * scalar };
		}

		vec4 vec4::divide(float scalar) const {
			return { x / scalar, y / scalar, z / scalar, w / scalar };
		}

		vec4 vec4::add(const vec4& vector) const {
			return { x + vector.x, y + vector.y, z + vector.z, w + vector.z };
		}

		vec4 vec4::subtract(const vec4& vector)const {
			return { x - vector.x, y - vector.y, z - vector.z, w - vector.z };
		}

		vec4 vec4::multiply(const vec4& vector) const {
			return { x * vector.x, y * vector.y, z * vector.z, w * vector.z };
		}

		vec4 vec4::divide(const vec4& vector) const {
			return { x / vector.x, y / vector.y, z / vector.z, w / vector.z };
		}

		vec4 operator+(const vec4& left, float scalar) {
			return left.add(scalar);
		}

		vec4 operator-(const vec4& left, float scalar) {
			return left.subtract(scalar);
		}

		vec4 operator*(const vec4& left, float scalar) {
			return left.multiply(scalar);
		}

		vec4 operator/(const vec4& left, float scalar) {
			return left.divide(scalar);
		}

		void operator+=(vec4& left, float scalar) {
			left = left.add(scalar);
		}

		void operator-=(vec4& left, float scalar) {
			left = left.subtract(scalar);
		}

		void operator*=(vec4& left, float scalar) {
			left = left.multiply(scalar);
		}

		void operator/=(vec4& left, float scalar) {
			left = left.divide(scalar);
		}

		vec4 operator+(const vec4& left, const vec4& right) {
			return left.add(right);
		}

		vec4 operator-(const vec4& left, const vec4& right) {
			return left.subtract(right);
		}

		vec4 operator*(const vec4& left, const vec4& right) {
			return left.multiply(right);
		}

		vec4 operator/(const vec4& left, const vec4& right) {
			return left.divide(right);
		}

		void operator+=(vec4& left, const vec4& right) {
			left = left.add(right);
		}

		void operator-=(vec4& left, const vec4& right) {
			left = left.subtract(right);
		}

		void operator*=(vec4& left, const vec4& right) {
			left = left.multiply(right);
		}

		void operator/=(vec4& left, const vec4& right) {
			left = left.divide(right);
		}

		bool operator==(vec4& left, const vec4& right) {
			return left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w;
		}

		bool operator!=(vec4& left, const vec4& right) {
			return !(left == right);
		}

		std::ostream& operator<<(std::ostream& stream, const ren::maths::vec4& vector) {
			stream << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w;
			return stream;
		}

	}

}