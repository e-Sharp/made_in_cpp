#pragma once

#include "empty.hpp"
#include "head.hpp"
#include "tail.hpp"
#include "list.hpp"

#include "mad/meta/type/same.hpp"
#include "mad/meta/type/type.hpp"

#include <cstdlib>
#include <type_traits>

namespace mad::meta {

template<typename... L, typename T> consteval
auto index(list<L...> l, type<T> t) {
	if constexpr(empty(l)) {
		static_assert(false, "mad: Type list does not contain given type.");
	} else if constexpr(same(head(l), t)) {
		return std::integral_constant<std::size_t, 0>();
	} else {
		return std::integral_constant<std::size_t, index(tail(l), t) + 1>();
	}
}

}
