#pragma once

#include "list.hpp"

#include "mad/meta/type/same.hpp"
#include "mad/meta/type/type.hpp"

#include <type_traits>

namespace mad::meta {

template<typename... L, typename T> consteval
bool contains(list<L...> l, type<T> t) {
	return (same(type<L>(), t) || ...);
}

}
