#pragma once

namespace sym::meta {

template<typename... Types>
struct types {
	constexpr types() {}
	constexpr types(Types...) {}
};

template<typename Type>
struct types<Type> {
	consteval types() = default;
	consteval types(Type) {};
};

template<typename Type>
types(Type) -> types<Type>;

template<>
struct types<> {};

}
