cmake_minimum_required(VERSION 3.16)

add_library(
  Zombie
  STATIC
  Zombie.hpp
  Zombie.cpp
)

target_link_libraries(
  Zombie
  GameObject
  GameWorld
)

target_include_directories(
  Zombie
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
)
