cmake_minimum_required(VERSION 3.10)

project(Breakout VERSION 1.0)

set(SFML_DIR "D:\\Code\\Languages\\C++\\3rd-Partys\\SFML-2.5.1\\lib\\cmake\\SFML")
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

set(CMAKE_BUILD_TYPE Debug)

add_library(external_deps INTERFACE)
target_link_libraries(external_deps INTERFACE
	sfml-graphics
	sfml-audio
	sfml-network
	sfml-system
	sfml-window
)



