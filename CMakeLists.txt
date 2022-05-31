cmake_minimum_required(VERSION 3.16)

project(bomberman VERSION 1.0.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME})

# Call the cmake that checks and pulls the raylib
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(raylib REQUIRED)
target_link_libraries(${PROJECT_NAME} raylib)

if(CMAKE_COMPILER_IS_GNUCXX)
    target_link_libraries(${PROJECT_NAME} -lstdc++fs)
endif(CMAKE_COMPILER_IS_GNUCXX)

set(CMAKE_CXX_STANDARD 17)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/main.cpp
        src/Text.cpp
        src/EventListener.cpp
        src/ButtonCallbacks.cpp
        src/MouseCallbacks.cpp
        src/GamepadStickCallbacks.cpp
        src/Shape3D.cpp
        src/Texture2D.cpp
        src/Camera.cpp
        src/Window.cpp
        test_functions/TestAnimations2D.cpp
        test_functions/TestCamera.cpp
        test_functions/TestEventListener.cpp
        test_functions/TestTextures.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        src/**
)

# Set default compile flags for GCC
if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "GCC detected, adding compile flags")
    target_compile_options(${PROJECT_NAME}
        PRIVATE
            -Wall
            -Wextra
    )
endif(CMAKE_COMPILER_IS_GNUCXX)

set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "../"
)

