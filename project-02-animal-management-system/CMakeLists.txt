cmake_minimum_required(VERSION 3.20)

project(animal-management
  VERSION 1.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(animal-management
  src/main.cpp
  src/utils.cpp
  src/Animal.cpp
  src/Dog.cpp
  src/Cat.cpp
  src/Bird.cpp
)

target_include_directories(animal-management
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/includes
)