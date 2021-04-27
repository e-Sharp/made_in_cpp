#pragma once

#include "symbolus/detail/tuple_like.hpp"

#include <tuple>

namespace sym {

template<tuple_like Functions, tuple_like Tuple> constexpr
auto apply_tuple(Functions&& fs, Tuple&& t) {
	return std::apply(
		[&t](const auto&... fs) {
			return std::forward_as_tuple(
				apply_tuple(
					std::forward<decltype(fs)>(fs),
					t
				)...);
		},
		std::forward<Functions>(fs));
}

}
