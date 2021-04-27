#pragma once

#include "types.hpp"

namespace sym::meta {

template<typename... T, typename... Args> constexpr
auto concatenation(types<T...> ts, Args&&... as) {
    return concatenation(ts, concatenation(as));
}

template<typename... L, typename... R> constexpr
auto concatenation(types<L...>, types<R...>) {
    return types<L..., R...>{};
}

}
