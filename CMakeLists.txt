cmake_minimum_required(VERSION 3.0)

project("json")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(jsoncpp REQUIRED)

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} jsoncpp_lib)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

target_link_libraries(json sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

FILE(COPY ${PROJECT_SOURCE_DIR}/ressources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

FILE(COPY ${PROJECT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


