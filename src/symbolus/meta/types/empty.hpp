#pragma once

#include "types.hpp"

namespace sym::meta {

template<typename... T> consteval
bool empty(types<T...>) { return false; }

consteval
bool empty(types<>) { return true; }

}
