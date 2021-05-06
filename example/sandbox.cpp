#include "symbolus2/all.hpp"

#include <cmath>
#include <iostream>
#include <tuple>

using namespace sym;
using namespace sym::notation::c;
using namespace sym::notation::p;


int main() {
	auto t = apply_tuple(apply_tuple(addition, std::tuple(p<0>, p<1>)), std::tuple(p<2>));
	std::cout << t << std::endl;
}
