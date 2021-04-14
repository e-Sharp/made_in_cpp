#pragma once

#include "list.hpp"

#include "mad/meta/type/type.hpp"

namespace mad::meta {

template<typename... L> consteval
void head(list<L...>) {
	static_assert(false, "mad: Empty list has no head.");
}

template<typename H, typename... T> consteval
type<H> head(list<H, T...>) { return {}; }

}
