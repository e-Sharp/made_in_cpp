#include "mad/make/unevaluated_context/prerequisite.hpp"

#include <catch.hpp>

#include <type_traits>

using namespace mad;

namespace n18675431 {

struct child {};
struct parent {};

auto prerequisite(child) -> meta::list<parent>;

template<typename C>
auto recipe(C c, child) {
	return prerequisite(c, meta::type<parent>());
}

template<typename C>
auto recipe(C, parent) {
	return int();
}

TEST_CASE(
	"make::prerequisite: "
	"Return type deduction.",
	"[make][detail]")
{
	constexpr auto c = make::unevaluated_context(
		make::command(meta::list<child>(), meta::list()),
		meta::type<child>());
	using p = decltype(prerequisite(c, meta::type<parent>()));
	REQUIRE(std::is_same_v<p, const int&>);
}

}
