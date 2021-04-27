
struct lvalue {};
struct rvalue {};

template<typename Type, typename Category>
struct reference;

template<typename Type>
struct reference<Type, lvalue> {
    template<typename Type_> constexpr
    reference(Type_& v)
        : value(v)
    {}

    Type& value;
};

template<typename Type>
struct reference<Type, rvalue> {
    constexpr reference(Type&& v)
        : value(std::move(v))
    {}

    Type&& value;
};

template<typename Type>
reference(const Type&) -> reference<const Type, lvalue>;

template<typename Type>
reference(Type&) -> reference<Type, lvalue>;

template<typename Type>
reference(Type&&) -> reference<Type, rvalue>;
