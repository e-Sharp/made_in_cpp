#pragma once

#include <type_traits>

namespace sym {

template<typename Type>
struct constant_ {
	static_assert(
		std::is_empty_v<Type>,
		"Only type constants are currently supported.");
};

template<typename Type, Type Value>
struct constant_<std::integral_constant<Type, Value>> {
	constexpr
	operator Type() const {
		return Value;
	}
};

template<typename C>
constexpr auto constant = constant_<C>();

template<typename C, typename Tuple> constexpr
decltype(auto) apply_tuple(const constant_<C>& c, Tuple&&) {
	return c;
}

template<typename T0, T0 V0, typename T1, T1 V1> constexpr
auto operator+(
	constant_<std::integral_constant<T0, V0>>,
	constant_<std::integral_constant<T1, V1>>)
{
	return constant<std::integral_constant<
		decltype(V0 + V1), V0 + V1>>;
}

}
