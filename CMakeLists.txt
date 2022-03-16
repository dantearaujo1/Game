cmake_minimum_required(VERSION 3.10)

project(Breakout VERSION 1.0)

#if not installed with cmake you need to set these variables
# Set the local directory of SFML
set(SFML_DIR "D:\\Code\\Languages\\C++\\3rd-Partys\\SFML-2.5.1\\lib\\cmake\\SFML")
# Set the local directory of TinyTMX
set(tinytmx_DIR "D:\\Code\\Languages\\C++\\3rd-Partys\\tinytmx\\lib\\cmake\\tinytmx")
# Set the local directory of Box2D
set(box2D_DIR "D:\\Code\\Languages\\C++\\3rd-Partys\\box2d\\lib\\cmake\\box2d\\")
# Set the local directory of ImGui-SFML
set(ImGui-SFML_DIR "D:\\Code\\Languages\\C++\\3rd-Partys\\imgui-sfml\\lib\\cmake\\ImGui-SFML")

# Looking for the LibraryConfig.cmake files
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
find_package(ImGui-SFML REQUIRED)
find_package(tinytmx REQUIRED)
find_package(box2D REQUIRED)

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

# Linking External Libraries - TinyTmx
target_link_libraries(external_deps INTERFACE
  tinytmx::tinytmx
)

# Linking External Libraries - Box2D
target_link_libraries(external_deps INTERFACE
  box2d::box2d
)

