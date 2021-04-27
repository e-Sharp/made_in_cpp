#pragma once

#include "types.hpp"

#include <type_traits>

namespace sym::meta {

template<typename... L, typename R> consteval
bool contains(types<L...> l, types<R> r) {
	return std::conjunction_v<std::is_same<L, R>...>;
}

}
