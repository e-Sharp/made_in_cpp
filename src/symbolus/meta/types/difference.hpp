#pragma once

#include "contains.hpp"
#include "tail.hpp"
#include "types.hpp"
#include "union.hpp"

namespace sym::meta {

template<typename... L, typename... R> constexpr
auto difference(types<L...> l, types<R...> r) {
    if constexpr(empty(l)) {
        return l;
    } else if constexpr(contains(r, head(l))) {
        return difference(tail(l), r);
    } else {
        return union_(head(l), difference(tail(l), r));
    }
}

}
