#pragma once

#include "symbolus/generic/constant.hpp"
#include "symbolus/generic/projection.hpp"
#include "symbolus/generic/tuple_application.hpp"

namespace sym {

struct multiplication_ {} constexpr multiplication;

template<typename Arg0, typename Arg1>
struct product_ : tuple_application<multiplication_, std::tuple<Arg0, Arg1>> {
	template<typename Arg0_, typename Arg1_> constexpr
	product_(Arg0_&& a0, Arg1_&& a1)
		: tuple_application<multiplication_, std::tuple<Arg0, Arg1>>(
			multiplication,
			std::forward_as_tuple(
				std::forward<Arg0_>(a0),
				std::forward<Arg1_>(a1)))
	{}
};

template<typename Arg0, typename Arg1>
product_(Arg0&&, Arg1&&) -> product_<Arg0, Arg1>;

template<typename Arg0, typename Arg1> constexpr
auto product(Arg0&& a0, Arg1&& a1) {
	return product_(
		std::forward<Arg0>(a0),
		std::forward<Arg1>(a1));
}

template<typename Arg> constexpr
auto product(zero_, Arg&&) {
	return zero;
}

template<typename Arg> constexpr
auto product(Arg&&, zero_) {
	return zero;
}

template<typename Arg> constexpr
auto product(one_, Arg&& a) {
	return std::forward<Arg>(a);
}

template<typename Arg> constexpr
auto product(Arg&& a, one_) {
	return std::forward<Arg>(a);
}

template<typename Arg0, typename Arg1> constexpr
auto operator*(Arg0&& a0, Arg1&& a1) {
	return product(
		std::forward<Arg0>(a0),
		std::forward<Arg1>(a1));
}

template<typename Tuple> constexpr
auto apply_tuple(multiplication_, Tuple&& t) {
	return apply_tuple(
		projection<0>,
		std::forward<Tuple>(t))
	* apply_tuple(
		projection<1>,
		std::forward<Tuple>(t));
}

}
