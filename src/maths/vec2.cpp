#include "vec2.h"

namespace ren {

	namespace maths {

		vec2::vec2() {
			x = 0.0f;
			y = 0.0f;
		}

		vec2::vec2(const float xy) {
			x = xy;
			y = xy;
		}

		vec2::vec2(const vec2& vector) : x(vector.x), y(vector.y) {}

		vec2::vec2(float x, float y) {
			this->x = x;
			this->y = y;
		}

		vec2 vec2::add(float scalar) const {
			return { x + scalar, y + scalar };
		}

		vec2 vec2::subtract(float scalar) const {
			return { x - scalar, y - scalar };
		}

		vec2 vec2::multiply(float scalar) const {
			return { x * scalar, y * scalar };
		}

		vec2 vec2::divide(float scalar) const {
			return { x / scalar, y / scalar };
		}

		vec2 vec2::add(const vec2& vector) const {
			return { x + vector.x, y + vector.y };
		}

		vec2 vec2::subtract(const vec2& vector)const {
			return { x - vector.x, y - vector.y };
		}

		vec2 vec2::multiply(const vec2& vector) const {
			return { x * vector.x, y * vector.y };
		}

		vec2 vec2::divide(const vec2& vector) const {
			return { x / vector.x, y / vector.y };
		}

		vec2 operator+(const vec2& left, float scalar) {
			return left.add(scalar);
		}

		vec2 operator-(const vec2& left, float scalar) {
			return left.subtract(scalar);
		}

		vec2 operator*(const vec2& left, float scalar) {
			return left.multiply(scalar);
		}

		vec2 operator/(const vec2& left, float scalar) {
			return left.divide(scalar);
		}

		void operator+=(vec2& left, float scalar) {
			left = left.add(scalar);
		}

		void operator-=(vec2& left, float scalar) {
			left = left.subtract(scalar);
		}

		void operator*=(vec2& left, float scalar) {
			left = left.multiply(scalar);
		}

		void operator/=(vec2& left, float scalar) {
			left = left.divide(scalar);
		}

		vec2 operator+(const vec2& left, const vec2& right) {
			return left.add(right);
		}

		vec2 operator-(const vec2& left, const vec2& right) {
			return left.subtract(right);
		}

		vec2 operator*(const vec2& left, const vec2& right) {
			return left.multiply(right);
		}

		vec2 operator/(const vec2& left, const vec2& right) {
			return left.divide(right);
		}

		void operator+=(vec2& left, const vec2& right) {
			left = left.add(right);
		}

		void operator-=(vec2& left, const vec2& right) {
			left = left.subtract(right);
		}

		void operator*=(vec2& left, const vec2& right) {
			left = left.multiply(right);
		}

		void operator/=(vec2& left, const vec2& right) {
			left = left.divide(right);
		}

		bool operator==(vec2& left, const vec2& right) {
			return left.x == right.x && left.y == right.y;
		}

		bool operator!=(vec2& left, const vec2& right) {
			return !(left == right);
		}

		std::ostream& operator<<(std::ostream& stream, const ren::maths::vec2& vector) {
			stream << vector.x << ", " << vector.y;
			return stream;
		}

	}

}