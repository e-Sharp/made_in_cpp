#pragma once

#include "types.hpp"

namespace sym::meta {

template<typename Type>
Type value(types<Type>);

template<typename... Args>
using value_t = decltype(value(Args...));

}
