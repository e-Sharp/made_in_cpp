add_executable(tests)

target_sources(tests
PRIVATE
	"mad/make/control_flow_graph/control_flow_graph.test.cpp"
	"mad/make/prerequisite/prerequisites.test.cpp"
	"mad/make/prerequisite/targets_with_prerequisite.test.cpp"
	"tests.cpp"
  "mad/make/unevaluated_context/prerequisite.test.cpp" "mad/make/unevaluated_context/targets.test.cpp" "mad/make/family_tree.hpp")

target_include_directories(tests
PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(tests
PRIVATE
	mad
)
