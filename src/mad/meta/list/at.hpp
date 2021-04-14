#pragma once

#include "empty.hpp"
#include "list.hpp"

#include <cstdlib>
#include <type_traits>

namespace mad::meta {

template<std::size_t I, typename... L> consteval
auto at(list<L...> l, std::integral_constant<std::size_t, I> = {}) {
	if constexpr(empty(l)) {
		static_assert(false, "mad: Out of range.");
	} else if constexpr(I == 0) {
		return head(l);
	} else {
		return at(tail(l), std::integral_constant<std::size_t, I - 1>());
	}
}

}
