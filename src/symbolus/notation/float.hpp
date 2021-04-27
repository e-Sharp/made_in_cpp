#pragma once

#include "symbolus/generic/constant.hpp"

#include <type_traits>

namespace sym {

template<float Value>
constexpr auto float_ = std::integral_constant<float, Value>();

}
