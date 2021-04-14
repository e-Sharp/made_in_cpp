#pragma once

#include "list.hpp"

namespace mad::meta {

template<typename... L> consteval
void tail(list<L...>) {
	static_assert(false, "mad: Empty list has no tail.");
}

template<typename H, typename... T> consteval
list<T...> tail(list<H, T...>) { return {}; }

}
