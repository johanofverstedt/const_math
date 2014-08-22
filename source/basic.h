
#ifndef CONST_MATH_BASIC_GUARD
#define CONST_MATH_BASIC_GUARD

#include "constants.h"

namespace const_math {
	template <typename T>
	constexpr T abs_value(T x) {
		return (x >= T(0))
			? x
			: (-x)
		;
	} 
	template <typename T>
	constexpr T minimum(T x, T y) {
		return (y < x) ? y : x;
	}
	template <typename T>
	constexpr T maximum(T x, T y) {
		return (y < x) ? x : y;
	}

	template <typename T>
	constexpr T half(T x) {
		return x / T(2);
	}

	template <typename T>
	constexpr T square(T x) {
		return x * x;
	}

	template <typename T>
	constexpr T cube(T x) {
		return x * x * x;
	}

	template <typename N>
	constexpr N factorial(N n) {
		return (n == N(0)) ? N(1) : (n * factorial(n - N(1)));
	}

	constexpr double reciprocal(double x) {
		return 1.0 / x;
	}

	constexpr double pi_mult(double x) {
		return x * PI;
	}
}

#endif
