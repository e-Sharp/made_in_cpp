#pragma once

#include "symbolus/generic/expand.hpp"

#include <tuple>

namespace sym {

template<typename... Args> constexpr
auto args(Args&&... as) {
	return expanded(
		std::forward_as_tuple(
			std::forward<Args>(as)...));
}

}
