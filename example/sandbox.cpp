#include "symbolus/all.hpp"

#include <cmath>
#include <iostream>

using namespace sym;
using namespace sym::notation::partial;
using namespace sym::notation::p01234;

int main() {
	constexpr auto l = partial < p0;
	std::cout << is_partial_derivative<decltype(l)>::value << std::endl;
	constexpr auto r = partial < p1;
	std::cout << is_partial_derivative<decltype(r)>::value << std::endl;
	apply(division, l, r);
	auto e = l / r;
	std::cout << typeid(l).name() << std::endl;
	std::cout << typeid(r).name() << std::endl;
	//std::cout << typeid(e).name() << std::endl;
}
