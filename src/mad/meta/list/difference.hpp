#pragma once

#include "contains.hpp"
#include "tail.hpp"
#include "union.hpp"

namespace mad::meta {

template<typename... L, typename... R> consteval
auto difference(list<L...> l, list<R...> r) {
    if constexpr(empty(l)) {
        return l;
    } else {
        constexpr auto t = difference(tail(l), r);
        if constexpr(contains(r, head(l))) {
            return t;
        } else {
            return union_(head(l), t);
        }
    }
}

}
