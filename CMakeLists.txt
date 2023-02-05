cmake_minimum_required(VERSION 3.0)

project("json")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

include(FetchContent)

set(SFML_VERSION 2.5.1)

set(FETCHCONTENT_QUIET OFF)

set(BUILD_SHARED_LIBS TRUE)

FetchContent_Declare(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG        "${SFML_VERSION}"
)

FetchContent_GetProperties(sfml)

if(NOT sfml_POPULATED)
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()



FetchContent_Declare(
	jsoncpp
	GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
	GIT_TAG master
)

FetchContent_GetProperties(jsoncpp)
if (NOT jsoncpp_POPULATED)
	FetchContent_Populate(jsoncpp)
	add_subdirectory(${jsoncpp_SOURCE_DIR} ${jsoncpp_BINARY_DIR})
endif()


FetchContent_MakeAvailable(jsoncpp)

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} jsoncpp_lib)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

FILE(COPY ${PROJECT_SOURCE_DIR}/ressources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

FILE(COPY ${PROJECT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
