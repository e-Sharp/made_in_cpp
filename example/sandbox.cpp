#include <mad/make/all.hpp>
#include <mad/meta/all.hpp>

#include <cmath>
#include <iostream>

using namespace mad::make;
using namespace mad::meta;

struct a {};
struct b {};
struct c {};

auto prerequisites(a) -> list<b>;
auto prerequisites(b) -> list<c>;

template<typename N>
void print(control_flow_node<N> n) {
	constexpr auto ts = N::targets();
	std::cout << ts << std::endl;
	if constexpr(!std::is_void_v<N::parent>) {
		print(N::parent());
	}
}

int main() {

}
