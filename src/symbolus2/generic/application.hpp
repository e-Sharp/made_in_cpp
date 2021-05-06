#pragma once

#include "symbolus2/generic/tuple.hpp"

#include <tuple>

namespace sym {

template<typename Function, typename Args>
struct application {
	template<typename Function_, typename Args_> constexpr
	application(Function_&& f, Args_&& as)
		: function(std::forward<Function_>(f))
		, args(std::forward<Args_>(as))
	{}

	Function function;
	Args args;
};

template<typename Function, typename Args>
application(Function, Args) -> application<Function, Args>;

template<typename... A, typename Tuple> constexpr
auto apply_tuple(const application<A...>& a, Tuple&& t) {
	return apply_tuple(
		a.function,
		apply_tuple(
			a.args,
			std::forward<Tuple>(t)));
}

template<typename... A, typename... Args_> constexpr
auto apply(const application<A...>& a, Args_&&... as) {
	return apply_tuple(
		a,
		std::forward_as_tuple(
			std::forward<Args_>(as)...));
}

}
