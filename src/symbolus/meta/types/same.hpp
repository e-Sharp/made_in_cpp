#pragma once

#include "types.hpp"

#include <type_traits>

namespace sym::meta {

template<typename... LL, typename... RL> consteval
bool same(types<LL...>, types<RL...>) {
	return std::is_same_v<types<LL...>, types<RL...>>;
}

}
