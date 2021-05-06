#pragma once

#include "symbolus2/generic/projection.hpp"

namespace sym::notation::p {

template<std::size_t I>
constexpr auto p = projection<I>();

}
