#pragma once

namespace sym {

template<typename Type>
struct constant {
	operator const Type&() const {
		return value;
	}

	Type value;
};

template<typename Type>
constant(Type) -> constant<Type>;

template<typename C, typename Tuple> constexpr
decltype(auto) apply_tuple(const constant<C>& c, Tuple&&) {
	return c;
}

template<typename C, typename... Types> constexpr
decltype(auto) apply(const constant<C>& c, Types&&...) {
	return c;
}

}
