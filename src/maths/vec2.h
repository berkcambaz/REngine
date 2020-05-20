#pragma once

#include <iostream>

namespace ren {

	namespace maths {

		struct vec2 {
			float x, y;

			vec2();
			vec2(const float xy);
			vec2(const vec2& vector);
			vec2(float x, float y);

			vec2 add(float scalar) const;
			vec2 subtract(float scalar) const;
			vec2 multiply(float scalar) const;
			vec2 divide(float scalar) const;

			vec2 add(const vec2& vector) const;
			vec2 subtract(const vec2& vector) const;
			vec2 multiply(const vec2& vector) const;
			vec2 divide(const vec2& vector) const;
		};

		vec2 operator+(const vec2& left, float scalar);
		vec2 operator-(const vec2& left, float scalar);
		vec2 operator*(const vec2& left, float scalar);
		vec2 operator/(const vec2& left, float scalar);

		void operator+=(vec2& left, float scalar);
		void operator-=(vec2& left, float scalar);
		void operator*=(vec2& left, float scalar);
		void operator/=(vec2& left, float scalar);

		vec2 operator+(const vec2& left, const vec2& right);
		vec2 operator-(const vec2& left, const vec2& right);
		vec2 operator*(const vec2& left, const vec2& right);
		vec2 operator/(const vec2& left, const vec2& right);

		void operator+=(vec2& left, const vec2& right);
		void operator-=(vec2& left, const vec2& right);
		void operator*=(vec2& left, const vec2& right);
		void operator/=(vec2& left, const vec2& right);

		bool operator==(vec2& left, const vec2& right);
		bool operator!=(vec2& left, const vec2& right);

		std::ostream& operator<<(std::ostream& stream, const ren::maths::vec2& vector);

	}

}