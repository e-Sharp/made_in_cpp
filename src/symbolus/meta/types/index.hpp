#pragma once

#include "empty.hpp"
#include "head.hpp"
#include "same.hpp"
#include "tail.hpp"
#include "types.hpp"

#include <cstdlib>
#include <type_traits>

namespace sym::meta {

template<typename... L, typename R> consteval
auto index(types<L...> l, types<R> r) {
	static_assert(!empty(l), "Out of range.");
	if constexpr(same(head(l), r)) {
		return std::integral_constant<std::size_t, 0>();
	} else {
		return std::integral_constant<std::size_t, index(tail(l), r) + 1>();
	}
}

}
