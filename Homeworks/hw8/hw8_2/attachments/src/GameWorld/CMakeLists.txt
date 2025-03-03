cmake_minimum_required(VERSION 3.16)

add_library(
  GameWorld
  STATIC
  GameWorld.hpp
  GameWorld.cpp
)

target_link_libraries(
  GameWorld
  GameObject
  Sun
  PlantingSpot
  Seed
  Plant
  Zombie
  Bullet
  Shovel
  HoldItem
)

target_include_directories(
  GameWorld
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Sun/
  ${CMAKE_SOURCE_DIR}/src/GameObject/PlantingSpot/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Seed/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Plant/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Zombie/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Shovel/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Bullet/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/HoldItem/
)
