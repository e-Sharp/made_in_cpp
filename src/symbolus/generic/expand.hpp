#pragma once

#include <utility>

namespace sym {

template<typename Tuple>
struct expanded {
	constexpr
	decltype(auto) operator*() {
        return std::forward<Tuple>(tuple);
    }

	Tuple tuple;
};

template<typename E>
expanded(E) -> expanded<E>;

template<typename Tuple> constexpr
auto expand(Tuple&& t) {
	return expanded<Tuple&&>(std::forward<Tuple>(t));
}

}
