#pragma once

#include "../sin.hpp"

#include "symbolus/detail/tuple_like.hpp"

#include <cmath>

namespace sym {

template<tuple_like Args>
decltype(auto) value(sin_, Args&& as) {
	if constexpr(tuple_size_v<Args> == 0) {
		return sin;
	} else {
		return std::sin(get<0>(std::forward<Args>(as)));
	}
}

}

