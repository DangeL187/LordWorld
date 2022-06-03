cmake_minimum_required(VERSION 3.23)

set(PROJECT_NAME LordWorld)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/split.h
)

find_package(SFML 2.5 COMPONENTS graphics audio)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)