#include "vec3.h"

namespace ren {

	namespace maths {

		vec3::vec3() {
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		vec3::vec3(const float xyzw) {
			x = xyzw;
			y = xyzw;
			z = xyzw;
		}

		vec3::vec3(const vec3& vector) : x(vector.x), y(vector.y), z(vector.z) {}

		vec3::vec3(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		vec3 vec3::add(float scalar) const {
			return { x + scalar, y + scalar, z + scalar };
		}

		vec3 vec3::subtract(float scalar) const {
			return { x - scalar, y - scalar, z - scalar };
		}

		vec3 vec3::multiply(float scalar) const {
			return { x * scalar, y * scalar, z * scalar };
		}

		vec3 vec3::divide(float scalar) const {
			return { x / scalar, y / scalar, z / scalar };
		}

		vec3 vec3::add(const vec3& vector) const {
			return { x + vector.x, y + vector.y, z + vector.z };
		}

		vec3 vec3::subtract(const vec3& vector)const {
			return { x - vector.x, y - vector.y, z - vector.z };
		}

		vec3 vec3::multiply(const vec3& vector) const {
			return { x * vector.x, y * vector.y, z * vector.z };
		}

		vec3 vec3::divide(const vec3& vector) const {
			return { x / vector.x, y / vector.y, z / vector.z };
		}

		vec3 operator+(const vec3& left, float scalar) {
			return left.add(scalar);
		}

		vec3 operator-(const vec3& left, float scalar) {
			return left.subtract(scalar);
		}

		vec3 operator*(const vec3& left, float scalar) {
			return left.multiply(scalar);
		}

		vec3 operator/(const vec3& left, float scalar) {
			return left.divide(scalar);
		}

		void operator+=(vec3& left, float scalar) {
			left = left.add(scalar);
		}

		void operator-=(vec3& left, float scalar) {
			left = left.subtract(scalar);
		}

		void operator*=(vec3& left, float scalar) {
			left = left.multiply(scalar);
		}

		void operator/=(vec3& left, float scalar) {
			left = left.divide(scalar);
		}

		vec3 operator+(const vec3& left, const vec3& right) {
			return left.add(right);
		}

		vec3 operator-(const vec3& left, const vec3& right) {
			return left.subtract(right);
		}

		vec3 operator*(const vec3& left, const vec3& right) {
			return left.multiply(right);
		}

		vec3 operator/(const vec3& left, const vec3& right) {
			return left.divide(right);
		}

		void operator+=(vec3& left, const vec3& right) {
			left = left.add(right);
		}

		void operator-=(vec3& left, const vec3& right) {
			left = left.subtract(right);
		}

		void operator*=(vec3& left, const vec3& right) {
			left = left.multiply(right);
		}

		void operator/=(vec3& left, const vec3& right) {
			left = left.divide(right);
		}

		bool operator==(vec3& left, const vec3& right) {
			return left.x == right.x && left.y == right.y && left.z == right.z;
		}

		bool operator!=(vec3& left, const vec3& right) {
			return !(left == right);
		}

		std::ostream& operator<<(std::ostream& stream, const ren::maths::vec3& vector) {
			stream << vector.x << ", " << vector.y << ", " << vector.z;
			return stream;
		}

	}

}