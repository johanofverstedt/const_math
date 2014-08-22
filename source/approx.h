
#ifndef CONST_MATH_APPROX_GUARD
#define CONST_MATH_APPROX_GUARD

namespace const_math {
	constexpr bool is_near(const double x, const double y, const double tolerance = 1.000000001) {
		return (x / y < tolerance && 1.0-x/y < tolerance);
	}

	namespace square_root_detail {
		constexpr const double next_guess(double x, double guess) {
			return 0.5 * x / guess + 0.5 * guess;
		}
	}
	constexpr const double square_root(const double x, const double guess=1.0) {
		return is_near(guess * guess, x) //(guess * guess / x < 1.000000001 && guess * guess / x > 0.999999999)
			? guess
			: sqrt_const(x, square_root_detail::next_guess(x, guess));
	}
}

#endif
