cmake_minimum_required(VERSION 3.16)

add_library(
  HoldItem
  STATIC
  HoldItem.hpp
  HoldItem.cpp
)

target_link_libraries(
  HoldItem
  GameObject
  GameWorld
)

target_include_directories(
  HoldItem
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
)
