#pragma once

#include <type_traits>
#include <utility>

namespace sym {

template<typename Type>
concept tuple_like = requires {
	std::tuple_size<std::remove_cvref_t<Type>>::value;
};

}
