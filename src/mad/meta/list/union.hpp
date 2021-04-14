#pragma once

#include "contains.hpp"
#include "head.hpp"
#include "tail.hpp"
#include "list.hpp"

#include "mad/meta/type/type.hpp"

namespace mad::meta {

template<typename... L, typename... Args> consteval
auto union_(list<L...> l, Args...) {
	return union_(l, union_(Args...));
}

template<typename... L> consteval
auto union_(list<L...> l) {
	return l;
}

template<typename... L, typename T> consteval
auto union_(list<L...> l, type<T> t) {
	if constexpr(contains(l, t)) {
		return l;
	} else {
		return list<L..., T>();
	}
}

template<typename... L> consteval
auto union_(list<L...> l, type<>) {
	return l;
}

template<typename T, typename... L> consteval
auto union_(type<T> t, list<L...> l) {
	if constexpr(contains(l, t)) {
		return l;
	} else {
		return list<T, L...>();
	}
}

template<typename... LL, typename... RL> consteval
auto union_(list<LL...> l, list<RL...> r) {
	if constexpr(empty(r)) {
		return l;
	} else if constexpr(contains(l, head(r))) {
		return union_(l, tail(r));
	} else {
		return union_(union_(l, head(r)), tail(r));
	}
}

}
