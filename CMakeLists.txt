cmake_minimum_required(VERSION 3.0.0)

project("json")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(jsoncpp REQUIRED)

file(GLOB SOURCES "src/*.cpp")

add_executable(json ${SOURCES})

target_link_libraries(json jsoncpp_lib)

FILE(COPY ${CMAKE_CURRENT_SOURCE_DIR}/ressources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

