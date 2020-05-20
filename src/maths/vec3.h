#pragma once

#include <iostream>

namespace ren {

	namespace maths {

		struct vec3 {
			float x, y, z;

			vec3();
			vec3(const float xyz);
			vec3(const vec3& vector);
			vec3(float x, float y, float z);

			vec3 add(float scalar) const;
			vec3 subtract(float scalar) const;
			vec3 multiply(float scalar) const;
			vec3 divide(float scalar) const;

			vec3 add(const vec3& vector) const;
			vec3 subtract(const vec3& vector) const;
			vec3 multiply(const vec3& vector) const;
			vec3 divide(const vec3& vector) const;
		};

		vec3 operator+(const vec3& left, float scalar);
		vec3 operator-(const vec3& left, float scalar);
		vec3 operator*(const vec3& left, float scalar);
		vec3 operator/(const vec3& left, float scalar);

		void operator+=(vec3& left, float scalar);
		void operator-=(vec3& left, float scalar);
		void operator*=(vec3& left, float scalar);
		void operator/=(vec3& left, float scalar);

		vec3 operator+(const vec3& left, const vec3& right);
		vec3 operator-(const vec3& left, const vec3& right);
		vec3 operator*(const vec3& left, const vec3& right);
		vec3 operator/(const vec3& left, const vec3& right);

		void operator+=(vec3& left, const vec3& right);
		void operator-=(vec3& left, const vec3& right);
		void operator*=(vec3& left, const vec3& right);
		void operator/=(vec3& left, const vec3& right);

		bool operator==(vec3& left, const vec3& right);
		bool operator!=(vec3& left, const vec3& right);

		std::ostream& operator<<(std::ostream& stream, const ren::maths::vec3& vector);

	}

}