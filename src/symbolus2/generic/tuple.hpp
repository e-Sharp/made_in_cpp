#pragma once

#include "symbolus2/concept/tuple_like.hpp"

#include <tuple>

namespace sym {

template<tuple_like T0, tuple_like T1> constexpr
auto apply_tuple(T0&& t0, T1&& t1) {
	return std::apply(
		[&t1](const auto&... es) {
			return std::forward_as_tuple(
				apply_tuple(es, t1)...);
		},
		t0);
}

template<tuple_like T, typename... Args> constexpr
auto apply(T&& t, Args&&... as) {
	return apply_tuple(
		std::forward<T>(t),
		std::forward_as_tuple(
			std::forward<Args>(as)...));
}

}
