#pragma once

#include "symbolus/arithmetic/all.hpp"
#include "symbolus/generic/all.hpp"

#include <type_traits>

namespace sym {

// Generic functions.

template<std::size_t I, typename C> constexpr
auto partial_derivative_of(const constant_<C>&) {
	return zero;
}

template<std::size_t I, std::size_t J> constexpr
auto partial_derivative_of(projection_<J>) {
	if constexpr(I == J) {
		return one;
	} else {
		return zero;
	}
}

// Arithmetic functions.

template<std::size_t I, typename Arg0, typename Arg1> constexpr
decltype(auto) partial_derivative_of_sum(Arg0&& a0, Arg1&& a1) {
	return partial_derivative_of<I>(std::forward<Arg0>(a0))
	+ partial_derivative_of<I>(std::forward<Arg1>(a1));
}

template<std::size_t I, typename Arg0, typename Arg1> constexpr
decltype(auto) partial_derivative_of(const product_<Arg0, Arg1>& p) {
	return partial_derivative_of<I>(get<0>(p.args))
	* get<1>(p.args)
	+ get<0>(p.args)
	* partial_derivative_of<I>(get<1>(p.args));
}

template<std::size_t I, typename... S> constexpr
decltype(auto) partial_derivative_of(const sum_<S...>& s) {
	return partial_derivative_of_sum<I>(get<0>(s.args), get<1>(s.args));
}

//

template<std::size_t I>
struct partial_derivative_ {};

template<std::size_t I>
constexpr auto partial_derivative = partial_derivative_<I>();

template<std::size_t I, tuple_like Tuple> constexpr
decltype(auto) apply_tuple(partial_derivative_<I>, Tuple&& t) {
	return partial_derivative_of<I>(
		apply_tuple(
			projection<0>,
			std::forward<Tuple>(t)));
}

}
