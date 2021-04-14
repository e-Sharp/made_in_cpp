#pragma once

#include "mad/meta/list/list.hpp"

#include <tuple>

namespace mad::meta {

template<typename... TL> constexpr
std::tuple<TL...> std_tuple_of(list<TL...>) { return {}; }

}
