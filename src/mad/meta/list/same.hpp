#pragma once

#include "list.hpp"

#include <type_traits>

namespace mad::meta {

template<typename... LL, typename... RL> consteval
bool same(list<LL...>, list<RL...>) {
	return std::is_same_v<list<LL...>, list<RL...>>;
}

}
