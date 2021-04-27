#pragma once

#include "../cos.hpp"

#include "symbolus/detail/tuple_like.hpp"

#include <cmath>

namespace sym {

template<tuple_like Args>
decltype(auto) value(cos_, Args&& as) {
	if constexpr(tuple_size_v<Args> == 0) {
		return cos;
	} else {
		return std::cos(get<0>(std::forward<Args>(as)));
	}
}

}

