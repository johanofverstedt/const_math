
#ifndef CONST_MATH_APPROX_GUARD
#define CONST_MATH_APPROX_GUARD

#include "basic.h"
#include "algorithms.h"

namespace const_math {
	constexpr bool is_near_rel(const double x, const double y, const double tolerance = 0.00000000001) {
		return abs_value(x / y - 1.0) < tolerance;
	}
	constexpr bool is_near_abs(const double x, const double y, const double tolerance = 0.00000000001) {
		return abs_value(x - y) < tolerance;
	}

	//Square root approximation

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

	//Trigonometric approximations

	constexpr const double modulo(const double x, const double m) {
		return (x >= 0)
			? (x - static_cast<int>(x / m) * m)
			: (m + (x - static_cast<int>(x / m) * m));
	}

	constexpr const double unit_circle_warp(const double x) {
		return modulo(x + PI, pi_mult(2.0)) - PI; 
	}

	constexpr const double trig_term(const double x, std::size_t n) {
		return power_n(x, n)/factorial_double(n, 1.0);
	}
	constexpr const double sin_inner(const double x, std::size_t terms, const double pos_accum, const double neg_accum) {
		return (terms == 1)
		? (pos_accum - neg_accum)
		: (is_odd(terms) ? (sin_inner(x, terms - 1, pos_accum + trig_term(x, 2 * terms - 1), neg_accum)) : (sin_inner(x, terms - 1, pos_accum, neg_accum + trig_term(x, 2 * terms - 1))));
	}
	constexpr const double sin(const double x) {
		return sin_inner(unit_circle_warp(x), 16ULL, unit_circle_warp(x), 0);//unit_circle_warp(x)
	}
	
	constexpr const double cos_inner(const double x, std::size_t terms, const double pos_accum, const double neg_accum) {
		return (terms == 1)
		? (pos_accum - neg_accum)
		: (is_odd(terms) ? (cos_inner(x, terms - 1, pos_accum + trig_term(x, 2 * terms - 2), neg_accum)) : (cos_inner(x, terms - 1, pos_accum, neg_accum + trig_term(x, 2 * terms - 2))));
	}
	constexpr const double cos(const double x) {
		return cos_inner(unit_circle_warp(x), 16ULL, 1.0, 0);//unit_circle_warp(x)
	}
}

#endif
