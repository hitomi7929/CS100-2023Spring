cmake_minimum_required(VERSION 3.16)

add_library(
  Object
  STATIC
  Object.hpp
  Object.cpp
)

target_link_libraries(
  Object
  GameObject
  GameWorld
)

target_include_directories(
  Object
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
)
