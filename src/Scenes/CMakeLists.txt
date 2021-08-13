include_directories(${PROJECT_SOURCE_DIR}/include/Scenes/)
add_library(scenes GameScene.cpp MenuScene.cpp)
target_link_libraries(scenes PUBLIC
                   sfml-graphics
                   sfml-audio
                   sfml-network
                   sfml-system
                   sfml-window
                   managers)
