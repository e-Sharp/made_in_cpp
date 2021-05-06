#pragma once

#include "symbolus/generic/constant.hpp"
#include "symbolus/generic/projection.hpp"
#include "symbolus/generic/tuple_application.hpp"

#include <iostream>

namespace sym {

struct addition_ {} constexpr addition;

template<typename Arg0, typename Arg1>
struct sum_ : tuple_application<addition_, std::tuple<Arg0, Arg1>> {
	template<typename Arg0_, typename Arg1_> constexpr
	sum_(Arg0_&& a0, Arg1_&& a1)
		: tuple_application<addition_, std::tuple<Arg0, Arg1>>(
			addition,
			std::forward_as_tuple(
				std::forward<Arg0_>(a0),
				std::forward<Arg1_>(a1)))
	{}
};

template<typename Arg0, typename Arg1>
sum_(Arg0&&, Arg1&&) -> sum_<Arg0, Arg1>;

template<typename Arg0, typename Arg1> constexpr
auto sum(Arg0&& a0, Arg1&& a1) {
	return sum_(
		std::forward<Arg0>(a0),
		std::forward<Arg1>(a1));
}

template<typename Arg0, typename Arg1> constexpr
auto operator+(Arg0&& a0, Arg1&& a1) {
	return sum(
		std::forward<Arg0>(a0),
		std::forward<Arg1>(a1));
}

template<typename Tuple> constexpr
auto apply_tuple(addition_, Tuple&& t) {
	return apply_tuple(
		projection<0>,
		std::forward<Tuple>(t))
	+ apply_tuple(
		projection<1>,
		std::forward<Tuple>(t));
}

}
