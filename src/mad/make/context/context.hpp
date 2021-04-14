#pragma once

namespace mad::make {

template<typename Type>
concept context = requires(Type value) {
	prerequisite();
};

}
