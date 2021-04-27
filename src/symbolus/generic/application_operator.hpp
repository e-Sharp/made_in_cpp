#pragma once

#include "symbolus/detail/tuple_like.hpp"
#include "symbolus/generic/expand.hpp"

#include <tuple>

namespace sym {

template<typename Function, typename Arg> constexpr
decltype(auto) operator<(Function&& f, Arg&& a) {
	return apply_tuple(
		std::forward<Function>(f),
		std::forward_as_tuple(std::forward<Arg>(a)));
}

template<typename Function, tuple_like Tuple> constexpr
decltype(auto) operator<(Function&& f, expanded<Tuple> t) {
	return apply_tuple(
		std::forward<Function>(f),
		*t);
}

template<typename Arg, typename Function> constexpr
decltype(auto) operator>(Arg&& a, Function&& f) {
	return operator<(
		std::forward<Function>(f),
		std::forward<Arg>(a));
}

}