#pragma once

#include "types.hpp"

namespace sym::meta {

template<typename... L> constexpr
void tail(types<L...>) {
	static_assert(false, "Out of range.");
}

template<typename H, typename... T> constexpr
types<T...> tail(types<H, T...>) { return {}; }

}
