#pragma once

#include "mad/meta/list/empty.hpp"
#include "mad/meta/list/head.hpp"
#include "mad/meta/list/tail.hpp"
#include "mad/meta/list/list.hpp"
#include "mad/meta/type_std/ostream.hpp"

namespace mad::meta {

template<typename... TL>
std::ostream& operator<<(std::ostream& os, list<TL...> l) {
	if constexpr(empty(l)) {
		return os;
	} else {
		constexpr auto h = head(l);
		constexpr auto t = tail(l);
		return os << h << " " << t;
	}
}

}
