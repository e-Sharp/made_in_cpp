#pragma once

#include "symbolus2/generic/application.hpp"

#include <any>

namespace sym {

struct addition_ {} constexpr addition;

template<typename Tuple>
struct sum : application<addition_, Tuple> {
	template<typename Tuple_> constexpr
	sum(Tuple_&& t)
		: application<addition_, Tuple>(
			addition, std::forward<Tuple_>(t))
	{}
};

template<typename LR, typename Tuple>
sum(reference<LR, Tuple>) -> sum<Tuple>;



template<typename Tuple> constexpr
auto apply(addition_, Tuple&& t) {
	return sum(
		std::forward<Tuple>(t));
}

template<typename Arg0, typename Arg1> constexpr
auto operator+(Arg0&& a0, Arg1&& a1) {
	return apply_tuple(
		addition,
		std::tuple(
			reference(std::forward<Arg0>(a0)),
			reference(std::forward<Arg1>(a1))));
}

}
