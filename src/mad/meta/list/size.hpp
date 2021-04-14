#pragma once

#include "list.hpp"

#include <cstdlib>

namespace mad::meta {

template<typename... L> consteval
std::size_t size(list<L...>) {
	return sizeof...(L);
}

}
