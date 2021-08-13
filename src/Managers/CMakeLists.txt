include_directories(${PROJECT_SOURCE_DIR}/include/Managers/)
add_library(managers SceneManager.cpp)

target_link_libraries(managers PUBLIC
                   sfml-graphics
                   sfml-audio
                   sfml-network
                   sfml-system
                   sfml-window
                   scenes)
