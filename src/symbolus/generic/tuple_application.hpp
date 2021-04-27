#pragma once

#include "symbolus/detail/tuple_like.hpp"

#include <iostream>

namespace sym {

template<typename Function, tuple_like Args>
struct tuple_application {
	Function function;
	Args args;
};

template<typename... A>
tuple_application(A...) -> tuple_application<A...>;

template<typename... A, tuple_like Tuple> constexpr
decltype(auto) apply_tuple(const tuple_application<A...>& a, Tuple&& t) {
	return apply_tuple(
		a.function,
		apply_tuple(
			a.args,
			std::forward<Tuple>(t)));
}

}
