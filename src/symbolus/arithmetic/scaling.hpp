#pragma once

#include "symbolus/generic/all.hpp"

namespace sym {

template<typename Type>
struct scaling {
	template<typename Type_> constexpr
	scaling(Type_&& v)
		: value(std::forward<Type_>(v))
	{}

	Type value;
};

template<typename Type>
scaling(Type) -> scaling<Type>;

template<typename S, typename Tuple> constexpr
auto apply_tuple(scaling<S>&& s, Tuple&& t) {
	return tuple_application(
		get<0>(std::forward<Tuple>(t)),
		std::tuple(
			projection<0>
			* std::move(s).value));
}

}
