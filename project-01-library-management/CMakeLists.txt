cmake_minimum_required(VERSION 3.20)

project(library-management
  VERSION 1.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(library-management
  src/main.cpp
  src/Book.cpp
  src/Library.cpp
)

target_include_directories(library-management
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/includes
)