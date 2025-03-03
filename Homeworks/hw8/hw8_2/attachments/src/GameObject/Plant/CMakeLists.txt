cmake_minimum_required(VERSION 3.16)

add_library(
  Plant
  STATIC
  Plant.hpp
  Plant.cpp
)

target_link_libraries(
  Plant
  GameObject
  GameWorld
  Bullet
)

target_include_directories(
  Plant
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Bullet/
)
