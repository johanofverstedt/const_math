
#ifndef CONST_MATH_APPROX_GUARD
#define CONST_MATH_APPROX_GUARD

#include "basic.h"

namespace const_math {
	constexpr bool is_near_rel(const double x, const double y, const double tolerance = 0.000000001) {
		return abs_value(x / y - 1.0) < tolerance;
	}
	constexpr bool is_near_abs(const double x, const double y, const double tolerance = 0.000000001) {
		return abs_value(x - y) < tolerance;
	}

	namespace square_root_detail {
		constexpr const double next_guess(double x, double guess) {
			return 0.5 * x / guess + 0.5 * guess;
		}
	}
	constexpr const double square_root(const double x, const double guess=1.0) {
		return is_near_rel(guess * guess, x) //(guess * guess / x < 1.000000001 && guess * guess / x > 0.999999999)
			? guess
			: square_root(x, square_root_detail::next_guess(x, guess));
	}
}

#endif
