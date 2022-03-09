cmake_minimum_required(VERSION 3.10)

project(Breakout VERSION 1.0)

#if not installed with cmake you need to set these variables
# Set the local directory of SFML
set(SFML_DIR "D:\\Code\\Languages\\C++\\3rd-Partys\\SFML-2.5.1\\lib\\cmake\\SFML")
# Set the local directory of ImGui-SFML
set(ImGui-SFML_DIR "D:\\Code\\Languages\\C++\\3rd-Partys\\imgui-sfml\\lib\\cmake\\ImGui-SFML")
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
find_package(ImGui-SFML REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

set(CMAKE_BUILD_TYPE Debug)

add_library(external_deps INTERFACE)

# Linking External Libraries - SFML
target_link_libraries(external_deps INTERFACE
	sfml-graphics
	sfml-audio
	sfml-network
	sfml-system
	sfml-window
)

# Linking External Libraries - IMGUI-SFML
target_link_libraries(external_deps INTERFACE
  ImGui-SFML::ImGui-SFML
)


