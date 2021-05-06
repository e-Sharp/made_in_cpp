add_executable(tests)

target_sources(tests
PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/symbolus/generic/tuple.test.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/tests.cpp
	"symbolus/generic/projection.test.cpp"
	"symbolus/generic/constant.test.cpp"
	"symbolus/generic/composition.test.cpp"
	"symbolus/generic/swap.test.cpp"
	"symbolus/arithmetic/addition.test.cpp"
 "symbolus/calculus/partial_derivative.test.cpp" "symbolus/generic/function.test.cpp")

target_include_directories(tests
PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(tests
PRIVATE
	symbolus
)
