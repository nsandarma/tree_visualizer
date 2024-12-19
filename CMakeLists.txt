cmake_minimum_required(VERSION 3.1...3.15)

project(tree_visualizer VERSION 1.0 LANGUAGES C)

file(GLOB SOURCES "src/*.c")

add_library(MyLib ${SOURCES})

target_include_directories(MyLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

find_package(raylib REQUIRED)

add_executable(${PROJECT_NAME} src/main.c)

target_link_libraries(${PROJECT_NAME} PRIVATE MyLib raylib)
