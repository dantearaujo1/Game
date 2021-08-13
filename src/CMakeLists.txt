set(MANAGER_DIRS ${PROJECT_SOURCE_DIR}/src/Managers})
set(SCENES_DIRS ${PROJECT_SOURCE_DIR}/src/Scenes/})

add_executable(${PROJECT_NAME}
    main.cpp
    Game.cpp
    ${MANAGER_DIRS}/SceneManager.cpp
    ${SCENES_DIRS}/GameScene.cpp
    ${SCENES_DIRS}/MenuScene.cpp
    )

set(EXECUTABLE_NAME "Dante")

add_subdirectory(Managers)
add_subdirectory(Scenes)
message(${CMAKE_BINARY_DIR})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_NAME ${EXECUTABLE_NAME}
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
    )

target_compile_features(${PROJECT_NAME}
    PRIVATE cxx_std_17)

target_link_libraries(${PROJECT_NAME} PRIVATE
	external_deps
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    managers
    scenes
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)
