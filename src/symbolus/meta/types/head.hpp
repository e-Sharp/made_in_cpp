#pragma once

#include "types.hpp"

namespace sym::meta {

template<typename... L> consteval
void head(types<L...>) {
	static_assert(false, "Out of range.");
}

template<typename H, typename... T> consteval
types<H> head(types<H, T...>) { return {}; }

}
