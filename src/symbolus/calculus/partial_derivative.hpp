#pragma once

#include "symbolus/arithmetic/all.hpp"
#include "symbolus/constant/all.hpp"
#include "symbolus/generic/all.hpp"

namespace sym {

struct partial_derivative_ {} constexpr partial_derivative;

template<typename Type>
struct is_partial_derivative
: std::false_type {};

template<typename Type>
struct is_partial_derivative<const Type>
: is_partial_derivative<Type> {};

template<typename Type>
struct is_partial_derivative<Type&>
: is_partial_derivative<Type> {};

template<typename Type>
struct is_partial_derivative<Type&&>
: is_partial_derivative<Type> {};

template<typename Remainder>
struct is_partial_derivative<tuple_application<partial_derivative_, Remainder>>
: std::true_type {};

template<typename Arg> constexpr
auto apply(partial_derivative_, Arg&& a) {
	return tuple_application(
		partial_derivative,
		std::tuple<Arg>(std::forward<Arg>(a)));
}

template<typename Operands> constexpr
auto apply(partial_derivative_, const tuple_application<addition_, Operands>& a) {
	return apply(
		partial_derivative,
		apply_tuple(
			projection<0>,
			a.args))
	+ apply(
		partial_derivative,
		apply_tuple(
			projection<1>,
			a.args));
}

template<typename Tuple> constexpr
auto apply_tuple(partial_derivative_, Tuple&& t) {
	return apply(
		partial_derivative,
		apply_tuple(
			projection<0>,
			std::forward<Tuple>(t)));
}



template<std::size_t I, std::size_t J> constexpr
decltype(auto) partial_derivative_apply(
	division_,
	const tuple_application<partial_derivative_, projection_<I>>&,
	const tuple_application<partial_derivative_, projection_<J>>&)
{
	return zero;
}

template<std::size_t I> constexpr
decltype(auto) partial_derivative_apply(
	division_,
	const tuple_application<partial_derivative_, projection_<I>>&,
	const tuple_application<partial_derivative_, projection_<I>>&)
{
	return one;
}

template<typename Arg0, typename Arg1>
requires (is_partial_derivative<Arg1>::value)
constexpr
decltype(auto) apply(division_, Arg0&& a0, Arg1&& a1) {
	return partial_derivative_apply(
		division,
		std::forward<Arg0>(a0),
		std::forward<Arg1>(a1));
}

}
