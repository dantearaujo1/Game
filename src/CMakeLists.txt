set(MANAGER_DIRS ${PROJECT_SOURCE_DIR}/src/Managers)
set(SCENES_DIRS ${PROJECT_SOURCE_DIR}/src/Scenes)
set(TOOLS_DIRS ${PROJECT_SOURCE_DIR}/src/Tools)
set(ECS_DIRS ${PROJECT_SOURCE_DIR}/src/ECS)

add_executable(${PROJECT_NAME}
    main.cpp
    Game.cpp
    EntityFactory.cpp
    Tile.cpp
    ${PROJECT_SOURCE_DIR}/include/Managers/Manager.hpp
    ${MANAGER_DIRS}/SceneManager.cpp
    ${MANAGER_DIRS}/TileManager.cpp
    ${MANAGER_DIRS}/AnimationManager.cpp
    ${TOOLS_DIRS}/TextureHelper.cpp
    ${SCENES_DIRS}/GameScene.cpp
    ${SCENES_DIRS}/MenuScene.cpp
    ${ECS_DIRS}/Systems/MovementSystem.cpp
    ${ECS_DIRS}/Systems/ControllerSystem.cpp
    ${ECS_DIRS}/Systems/AnimationSystem.cpp
    ${ECS_DIRS}/Systems/RenderSystem.cpp
    )

set(EXECUTABLE_NAME "Dante")


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


target_include_directories(${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)
