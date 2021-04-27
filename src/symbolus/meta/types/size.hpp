#pragma once

#include "types.hpp"

#include <cstdlib>

namespace sym::meta {

template<typename... L> consteval
std::size_t size(types<L...>) {
	return sizeof...(L);
}

}
