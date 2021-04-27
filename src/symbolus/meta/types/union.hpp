#pragma once

#include "concatenation.hpp"
#include "contains.hpp"
#include "head.hpp"
#include "tail.hpp"
#include "types.hpp"

namespace sym::meta {

template<typename... T, typename... Args> consteval
auto union_(types<T...> ts, Args...) {
	return union_(ts, union_(Args...));
}

template<typename... L, typename... R> consteval
auto union_(types<L...> l, types<R...> r) {
	if constexpr(empty(r)) {
		return l;
	} else if constexpr(contains(l, head(r))) {
		return union_(l, tail(r));
	} else {
		return union_(concatenation(l, head(r)), tail(r));
	}
}

}
