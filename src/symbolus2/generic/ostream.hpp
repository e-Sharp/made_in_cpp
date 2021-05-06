#pragma once

#include "application.hpp"
#include "constant.hpp"
#include "function.hpp"
#include "projection.hpp"
#include "tuple.hpp"

#include "symbolus2/concept/tuple_like.hpp"

#include <iostream>

namespace sym {

void print(std::ostream&) {}

template<typename Type, typename... Types>
void print(std::ostream& os, const Type& v, const Types&... vs) {
	os << v << ",";
	print(os, vs...);
}

template<typename Arg>
void print(std::ostream& os, const Arg& a) {
	os << a;
}

template<typename... A> constexpr
auto& operator<<(std::ostream& os, const application<A...>& a) {
	return os << a.function << a.args;
}

template<typename C>
auto& operator<<(std::ostream& os, const constant<C>& c) {
	return os << c.value;
}

template<typename F>
auto& operator<<(std::ostream& os, const function<F>& f) {
	return os << "function<" << f.object << ">";
}

template<std::size_t I>
auto& operator<<(std::ostream& os, projection<I>) {
	return os << "p" << I;
}

template<tuple_like T>
auto& operator<<(std::ostream& os, const T& t) {
	os << "(";
	std::apply([&os](const auto&... args) { print(os, args...); }, t);
	return os << ")";
}

}
