#pragma once

#include "symbolus/generic/projection.hpp"
#include "symbolus/generic/tuple.hpp"

#include <tuple>

namespace sym {

constexpr auto swap = std::tuple(projection<1>, projection<0>);

}
