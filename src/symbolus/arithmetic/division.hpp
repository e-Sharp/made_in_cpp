#pragma once

#include "symbolus/generic/projection.hpp"
#include "symbolus/generic/tuple.hpp"
#include "symbolus/generic/tuple_application.hpp"

#include <iostream>

namespace sym {

struct division_ {} constexpr division;

template<typename Arg0, typename Arg1> constexpr
auto apply(division_, Arg0&& a0, Arg1&& a1) {
	return tuple_application(
		division,
		std::tuple<Arg0, Arg1>(
			std::forward<Arg0>(a0),
			std::forward<Arg1>(a1)));
}

template<typename Arg0, typename Arg1> constexpr
auto operator/(Arg0&& a0, Arg1&& a1) {
	return apply(
		division,
		std::forward<Arg0>(a0),
		std::forward<Arg1>(a1));
}

template<typename Tuple> constexpr
auto apply_tuple(division_, Tuple&& t) {
	return apply_tuple(
		projection<0>,
		std::forward<Tuple>(t))
	/ apply_tuple(
		projection<1>,
		std::forward<Tuple>(t));
}

}