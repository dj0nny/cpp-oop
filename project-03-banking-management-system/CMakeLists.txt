cmake_minimum_required(VERSION 3.20)

project(animal-management
  VERSION 1.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(banking-management
  src/main.cpp
)

target_include_directories(banking-management
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/includes
)