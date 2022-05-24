cmake_minimum_required(VERSION 3.16)

project(bomberman VERSION 1.0.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME})

# Call the cmake that checks and pulls the raylib
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(raylib REQUIRED)
target_link_libraries(${PROJECT_NAME} raylib -lstdc++fs)

set(CMAKE_CXX_STANDARD 17)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/main.cpp
        src/shape3d.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_compile_options(${PROJECT_NAME}
    PRIVATE
        -Wall
        -Wextra
)

set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "../"
)

