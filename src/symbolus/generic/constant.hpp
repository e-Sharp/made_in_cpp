#pragma once

#include <type_traits>

namespace sym {

template<typename Type>
struct constant {
	template<typename... Types> constexpr
	decltype(auto) operator()(Types&&...) const {
		return *this;
	}

	template<typename Tuple> constexpr
	decltype(auto) operator()(Tuple&&) const {
		return *this;
	}

	Type value;
};

template<typename Type>
constant(Type) -> constant<Type>;

template<typename C, typename Tuple> constexpr
decltype(auto) apply_tuple(const constant<C>& c, Tuple&&) {
	return c;
}

template<typename C0, typename C1> constexpr
auto operator+(constant<C0> c0, constant<C1> c1) {
	return constant(c0.value + c1.value);
}

template<typename C0, typename C1> constexpr
auto operator*(constant<C0> c0, constant<C1> c1) {
	return constant(c0.value * c1.value);
}

}
