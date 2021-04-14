#pragma once

#include "type.hpp"

namespace mad::meta {

template<typename T> constexpr
T value(type<T>);

}
