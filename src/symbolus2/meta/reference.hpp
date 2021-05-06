#pragma once

namespace sym {

struct lvalue {};
struct rvalue {};

template<typename Category, typename Type>
struct reference;

template<typename Type>
struct reference<lvalue, Type> {
    constexpr operator const Type&() const {
        return value;
    }

    constexpr operator Type&() {
        return value;
    }

    Type& value;
};

template<typename Type>
reference(Type&) -> reference<lvalue, Type>;

template<typename Type>
using lvalue_reference = reference<lvalue, Type>;

template<typename Type>
struct reference<rvalue, Type> {
    constexpr operator Type&&() {
        return std::move(value);
    }

    Type&& value;
};

template<typename Type>
reference(Type&&) -> reference<rvalue, Type>;

template<typename Type>
using rvalue_reference = reference<rvalue, Type>;

}
