#pragma once

#include "type.hpp"

namespace mad::meta {

template<typename T> consteval
type<T> type_of(T) { return {}; }

}
