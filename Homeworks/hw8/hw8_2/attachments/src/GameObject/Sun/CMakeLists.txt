cmake_minimum_required(VERSION 3.16)

add_library(
  Sun
  STATIC
  Sun.hpp
  Sun.cpp
)

target_link_libraries(
  Sun
  GameObject
  GameWorld
)

target_include_directories(
  Sun
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
)
