#include "mad/make/prerequisite/prerequisites.hpp"

#include <catch.hpp>

#include <type_traits>

using namespace mad;

namespace n1341234 {

struct a {};

TEST_CASE(
	"make::prerequisites: "
	"No prerequisite.",
	"[make]")
{
	constexpr auto ps = make::prerequisites(meta::list<a>(), meta::list());

	constexpr auto s = same(ps, meta::list());
	REQUIRE(s);
}

}

namespace n1234734 {

struct a {};
struct b {};

auto prerequisites(a) -> meta::list<b>;

TEST_CASE(
	"make::prerequisites: "
	"Single prerequisite.",
	"[make]")
{
	constexpr auto ps = make::prerequisites(meta::list<a>(), meta::list());

	constexpr auto s = same(ps, meta::list<b>());
	REQUIRE(s);
}

}


namespace n345738 {

struct a {};
struct b {};
struct c {};
struct d {};

auto prerequisites(a) -> meta::list<b>;
auto prerequisites(c) -> meta::list<d>;

TEST_CASE(
	"make::prerequisites: "
	"Two trees.",
	"[make]")
{
	constexpr auto ps = make::prerequisites(meta::list<a, c>(), meta::list());

	constexpr auto s = same(ps, meta::list<b, d>());
	REQUIRE(s);
}

}

