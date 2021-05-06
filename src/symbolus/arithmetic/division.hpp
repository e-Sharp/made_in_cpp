#pragma once

#include "symbolus/generic/constant.hpp"
#include "symbolus/generic/projection.hpp"
#include "symbolus/generic/tuple_application.hpp"

#include <iostream>

namespace sym {

struct division_ {} constexpr division;

template<typename Arg0, typename Arg1>
struct quotient_ : tuple_application<division_, std::tuple<Arg0, Arg1>> {
	template<typename Arg0_, typename Arg1_> constexpr
	quotient_(Arg0_&& a0, Arg1_&& a1)
		: tuple_application<division_, std::tuple<Arg0, Arg1>>(
			division,
			std::forward_as_tuple(
				std::forward<Arg0_>(a0),
				std::forward<Arg1_>(a1)))
	{}
};

template<typename Arg0, typename Arg1>
quotient_(Arg0&&, Arg1&&) -> quotient_<Arg0, Arg1>;

template<typename Arg0, typename Arg1> constexpr
auto quotient(Arg0&& a0, Arg1&& a1) {
	return quotient_(
		std::forward<Arg0>(a0),
		std::forward<Arg1>(a1));
}

template<typename Arg> constexpr
auto quotient(zero_, Arg&& a) {
	return zero;
}

template<typename Arg0, typename Arg1> constexpr
auto operator/(Arg0&& a0, Arg1&& a1) {
	return division(
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
