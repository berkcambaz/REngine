#pragma once

namespace ren {

	namespace maths {

#define PI 3.14159265358f

		inline float toRadians(float degrees) {
			return degrees * PI / 180.0f;
		}

	}

}