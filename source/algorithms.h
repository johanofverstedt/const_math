
#ifndef CONST_MATH_ALGORITHMS_GUARD
#define CONST_MATH_ALGORITHMS_GUARD

#include "basic.h"
#include "constants.h"

namespace const_math {
	//Russian Peasant Algorithm for computing multiplicative powers with
	//integer exponent: x^y => pow_n(x, n), where x may be double but n
	//must be integer typed.

	namespace detail { //Implementation details of power_n
		template <typename T, typename N>
		constexpr const T power_n_pos(const T x, const N n) {
			return (n == 1)
				? x
				: (is_even(n) ? power_n_pos(x*x, n/N(2)) : (x * power_n_pos(x*x, n/N(2))));
		}
	}

	template <typename T, typename N>
	constexpr const T power_n(const T x, const N n) {
		return (n == 0)
			? T(1)
			: (n < N(1)) ? (T(1) / detail::power_n_pos(x, abs_value(n))) : detail::power_n_pos(x, n); 
	}
}

#endif
