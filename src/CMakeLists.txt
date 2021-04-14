add_library(decl INTERFACE)

target_include_directories(decl INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(mad INTERFACE)

target_include_directories(mad
INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}
)
