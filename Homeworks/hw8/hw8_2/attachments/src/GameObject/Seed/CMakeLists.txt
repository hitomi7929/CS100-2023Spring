cmake_minimum_required(VERSION 3.16)

add_library(
  Seed
  STATIC
  Seed.hpp
  Seed.cpp
)

target_link_libraries(
  Seed
  GameObject
  GameWorld
  CooldownMask
  HoldItem
)

target_include_directories(
  Seed
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/CooldownMask/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/HoldItem/
)
