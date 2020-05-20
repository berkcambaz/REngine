#pragma once

#include <iostream>

namespace ren {

	namespace maths {

		struct vec4 {
			float x, y, z, w;

			vec4();
			vec4(const float xyzw);
			vec4(const vec4& vector);
			vec4(float x, float y, float z, float w);

			vec4 add(float scalar) const;
			vec4 subtract(float scalar) const;
			vec4 multiply(float scalar) const;
			vec4 divide(float scalar) const;

			vec4 add(const vec4& vector) const;
			vec4 subtract(const vec4& vector) const;
			vec4 multiply(const vec4& vector) const;
			vec4 divide(const vec4& vector) const;
		};

		vec4 operator+(const vec4& left, float scalar);
		vec4 operator-(const vec4& left, float scalar);
		vec4 operator*(const vec4& left, float scalar);
		vec4 operator/(const vec4& left, float scalar);

		void operator+=(vec4& left, float scalar);
		void operator-=(vec4& left, float scalar);
		void operator*=(vec4& left, float scalar);
		void operator/=(vec4& left, float scalar);

		vec4 operator+(const vec4& left, const vec4& right);
		vec4 operator-(const vec4& left, const vec4& right);
		vec4 operator*(const vec4& left, const vec4& right);
		vec4 operator/(const vec4& left, const vec4& right);

		void operator+=(vec4& left, const vec4& right);
		void operator-=(vec4& left, const vec4& right);
		void operator*=(vec4& left, const vec4& right);
		void operator/=(vec4& left, const vec4& right);

		bool operator==(vec4& left, const vec4& right);
		bool operator!=(vec4& left, const vec4& right);

		std::ostream& operator<<(std::ostream& stream, const ren::maths::vec4& vector);

	}

}