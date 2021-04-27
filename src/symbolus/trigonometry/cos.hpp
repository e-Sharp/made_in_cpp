#pragma once

#include "symbolus/generic/function.hpp"

namespace sym {

struct cos_ : function<cos_> {};

constexpr auto cos = cos_();

}
