cmake_minimum_required(VERSION 3.25)
project(game_engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

if(NOT EXISTS "${CMAKE_BINARY_DIR}/assets")
  file(CREATE_LINK
    "${CMAKE_CURRENT_SOURCE_DIR}/assets"
    "${CMAKE_BINARY_DIR}/assets"
    SYMBOLIC)
endif()

target_include_directories(
  ${PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  glad::glad
  glfw
  glm::glm
)

target_precompile_headers(${PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include/common.hpp
)
