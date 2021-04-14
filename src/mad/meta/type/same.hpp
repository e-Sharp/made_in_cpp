#pragma once

#include "type.hpp"

namespace mad::meta {

template<typename A, typename B> consteval
bool same(type<A>, type<B>) { return false; }

template<typename T> consteval
bool same(type<T>, type<T>) { return true; }

}
