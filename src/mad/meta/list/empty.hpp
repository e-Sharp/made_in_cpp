#pragma once

#include "list.hpp"

namespace mad::meta {

template<typename... L> consteval
bool empty(list<L...>) { return false; }

consteval
bool empty(list<>) { return true; }

}
