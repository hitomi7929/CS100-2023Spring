cmake_minimum_required(VERSION 3.16)

add_library(
  Bullet
  STATIC
  Bullet.hpp
  Bullet.cpp
)

target_link_libraries(
  Bullet
  GameObject
  GameWorld
)

target_include_directories(
  Bullet
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
)
