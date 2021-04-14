#include "mad/make/control_flow_graph/control_flow_graph.hpp"

#include <catch.hpp>

#include <type_traits>

#include <iostream>

using namespace mad;

namespace n154623462 {

struct a {};
struct b {};
struct c {};

auto prerequisites(a) -> meta::list<b>;
auto prerequisites(b) -> meta::list<c>;

template<typename N>
void print(make::control_flow_node<N> n) {
	constexpr auto ts = N::targets();
	std::cout << ts << std::endl;
	if constexpr(!std::is_void_v<N::parent>) {
		print(N::parent());
	}
}

TEST_CASE(
	"make::control_flow_graph: "
	"Sandbox #1.",
	"[make][sandbox]")
{
	constexpr auto g = make::control_flow_graph(
		meta::list<a, b>(), meta::list());
	// print(g);
}

}
