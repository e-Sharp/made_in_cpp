#pragma once

namespace mad::meta {

template<typename... Ts>
struct list {
	constexpr list() {}
	constexpr list(Ts...) {}
};

template<>
struct list<> {};

}
