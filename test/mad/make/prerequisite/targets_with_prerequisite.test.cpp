#include "mad/make/prerequisite/targets_with_prerequisite.hpp"

#include <catch.hpp>

#include <type_traits>

using namespace mad;

namespace n3048965093 {

struct a {};
struct b {};

auto prerequisites(a) -> meta::list<b>;

TEST_CASE(
	"make::targets_with_prerequisite: "
	"Direct prerequisite.",
	"[make]")
{
	constexpr auto ts = make::targets_with_prerequisite(
		meta::list<a>(), meta::type<b>(), meta::list<>());

	constexpr auto s = same(ts, meta::list<a>());
	REQUIRE(s);
}

}

namespace n8674931 {

struct a {};
struct b {};
struct c {};

auto prerequisites(a) -> meta::list<b>;
auto prerequisites(b) -> meta::list<c>;

TEST_CASE(
	"make::targets_with_prerequisite: "
	"Undirect prerequisite.",
	"[make]")
{
	constexpr auto ts = make::targets_with_prerequisite(
		meta::list<a>(), meta::type<c>(), meta::list<>());

	constexpr auto s = same(ts, meta::list<b>());
	REQUIRE(s);
}

}

namespace n934850363 {

struct a {};
struct b {};

TEST_CASE(
	"make::targets_with_prerequisite: "
	"Unrelated target without any prerequisite.",
	"[make]")
{
	constexpr auto ts = make::targets_with_prerequisite(
		meta::list<a>(), meta::type<b>(), meta::list<>());

	constexpr auto s = same(ts, meta::list());
	REQUIRE(s);
}

}

namespace n24534643 {

struct a {};
struct b {};
struct c {};

auto prerequisites(a) -> meta::list<b>;
auto prerequisites(b) -> meta::list<c>;

TEST_CASE(
	"make::targets_with_prerequisite: "
	"Grandchild and child.",
	"[make]")
{
	constexpr auto ts = make::targets_with_prerequisite(
		meta::list<a, b>(), meta::type<c>(), meta::list<>());

	constexpr auto s = same(ts, meta::list<b>());
	REQUIRE(s);
}

}
