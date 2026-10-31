cmake_minimum_required(VERSION 3.20)

project(battle-arena
  VERSION 1.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(battle-arena
  src/main.cpp
)

target_include_directories(battle-arena
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/includes
)