
#ifndef CONST_MATH_BASIC_GUARD
#define CONST_MATH_BASIC_GUARD

#include <cstdint>

#include "constants.h"

namespace const_math {
	template <typename T>
	constexpr T abs_value(T x) {
		return (x >= T(0))
			? x
			: (-x)
		;
	}
	
	//This ugliness could be avoided by overloading on UnsignedInteger concept
	//in the future...

	template <>
	constexpr std::uint8_t abs_value<std::uint8_t>(std::uint8_t x) { return x; }
	template <>
	constexpr std::uint16_t abs_value<std::uint16_t>(std::uint16_t x) { return x; }
	template <>
	constexpr std::uint32_t abs_value<std::uint32_t>(std::uint32_t x) { return x; }
	template <>
	constexpr std::uint64_t abs_value<std::uint64_t>(std::uint64_t x) { return x; }

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
	constexpr double factorial_double(N n, double accum) {
		return (n == N(0)) ? accum : (factorial_double(n - N(1), accum * double(n)));
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

	template <typename N>
	constexpr bool is_even(N n) {
		return (n % N(2) == N(0));
	}
	template <typename N>
	constexpr bool is_odd(N n) {
		return (n % N(2) != N(0));
	}

	template <typename N>
	constexpr N make_even_up(N n) {
		return is_even(n) ? n : (n+N(1));
	}
	template <typename N>
	constexpr N make_even_down(N n) {
		return is_even(n) ? n : (n-N(1));
	}
}

#endif
