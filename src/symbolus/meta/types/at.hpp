#pragma once

#include "empty.hpp"
#include "head.hpp"
#include "types.hpp"

#include <cstdlib>
#include <type_traits>

namespace sym::meta {

template<std::size_t I, typename... T> consteval
auto at(types<T...> ts, std::integral_constant<std::size_t, I> = {}) {
	static_assert(!empty(ts), "Out of range.");
	if constexpr(I == 0) {
		return head(ts);
	} else {
		return at(tail(ts), std::integral_constant<std::size_t, I - 1>());
	}
}

}
