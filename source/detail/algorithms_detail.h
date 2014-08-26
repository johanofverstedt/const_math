
#ifndef CONST_MATH_ALGORITHMS_DETAIL_GUARD
#define CONST_MATH_ALGORITHMS_DETAIL_GUARD

namespace const_math {
	//Implementation details for power_n function
	namespace detail {
		template <typename T, typename N>
		//requires Numeric(T),
		//requires Integer(N)
		constexpr const T power_n_positive(const T x, const N n) {
			return (n == 1)
				? x
				: (is_even(n) ? power_n_positive(x*x, n/N(2)) : (x * power_n_positive(x*x, n/N(2))));
		}
	}
}

#endif
