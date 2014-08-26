
#ifndef CONST_MATH_ALGORITHMS_GUARD
#define CONST_MATH_ALGORITHMS_GUARD

#include <exception>
#include <type_traits>
#include <utility>

#include "basic.h"
#include "constants.h"

//Detail headers

#include "detail/algorithms_detail.h"

namespace const_math {
	template<typename Op, typename... T>
	struct TypeOfReduction;

	template<typename Op, typename T>
	struct TypeOfReduction<Op, T> {
    	typedef T       type;
	};

	template<typename Op, typename T, typename... P>
	struct TypeOfReduction<Op, T,P...> {
    	typedef decltype(Op()(T(), typename TypeOfSum<P...>::type()))        type;
	};

/*
	constexpr int sum_recursive() {
		return 0;
	}
	template <typename T>
	constexpr T sum_recursive(T x) {
		return x;
	}
	template <typename R, typename T, typename ...A>
	constexpr typename TypeOfSum<R, T, A...>::type sum_recursive(R accum, T x, const A... tail) {
		return sum_recursive(accum + x, tail...);
	}
	template <typename ...A>
	constexpr typename TypeOfSum<A...>::type sum(A... terms) {
		return sum_recursive(0, terms...);
	}*/

	template <typename Op, typename T>
	T
	fold_left(Op op, T head) {
		return head;
	}

	template <typename Op, typename T, typename ...Args>
	typename TypeOfReduction<Op, T, Args...>::type
	fold_left(Op op, T head, Args... tail) {
		return op(head, fold_left(op, tail...));
	}

	struct add_const_op {
		constexpr add_const_op() {}

		template <typename T, typename U>
		
		typename std::common_type<T, U>::type operator()(const T& x, const U& y) {
			return x + y;
		}
	};

	template <typename T, typename ...Args>
	auto add(T head, Args... tail) -> typename decltype(fold_left(add_const_op(), head, tail...)) {
		return fold_left(add_const_op(), head, tail...);
	}


	constexpr int product() {
		return 1;
	}
	template <typename T, typename ...A>
	constexpr T product(T x, const A... tail) {
		return x * product(tail...);
	}

	//
	// power_n
	//
	// Russian Peasant Algorithm for recursively computing multiplicative powers with
	// integer exponent: x^y => power_n(x, n) in O(log(n)) time which
	// means that it will finish in at most 64 recursive calls worst-case for
	// primitive integer types on a 64-bit native platform.
	//

	template <typename T, typename N>
	//requires Numeric(T)
	//requires Integer(N)
	constexpr const T power_n(const T x, const N n) {
		return (n == 0)
			? T(1)
			: (n < N(1)) ? (T(1) / detail::power_n_positive(x, abs_value(n))) : detail::power_n_positive(x, n); 
	}
}

#endif
