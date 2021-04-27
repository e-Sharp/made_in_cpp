#pragma once

#include "symbolus/generic/function.hpp"

namespace sym {

struct sin_ : function<sin_> {};

constexpr auto sin = sin_();

}
