cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME "PvZ")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)


########### MAGIC THAT YOU DO NOT NEED TO MODIFY #############
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")

add_subdirectory(
  "${CMAKE_CURRENT_LIST_DIR}/third_party/SOIL/"
  "${CMAKE_CURRENT_BINARY_DIR}/SOIL"
  EXCLUDE_FROM_ALL
)

add_subdirectory(
  "${CMAKE_CURRENT_LIST_DIR}/third_party/freeglut/"
  "${CMAKE_CURRENT_BINARY_DIR}/freeglut"
  EXCLUDE_FROM_ALL
)
##############################################################


#↓↓↓↓↓↓↓↓↓↓↓ ADD YOUR SUBDIRECTORIES HERE ↓↓↓↓↓↓↓↓↓↓↓↓
add_subdirectory(src/Framework/)
add_subdirectory(src/GameWorld/)
add_subdirectory(src/GameObject/)
add_subdirectory(src/GameObject/Sun/)
add_subdirectory(src/GameObject/PlantingSpot/)
add_subdirectory(src/GameObject/Seed/)
add_subdirectory(src/GameObject/Plant/)
add_subdirectory(src/GameObject/Zombie/)
add_subdirectory(src/GameObject/CooldownMask/)
add_subdirectory(src/GameObject/Shovel/)
add_subdirectory(src/GameObject/Bullet/)
add_subdirectory(src/GameObject/Object/)
add_subdirectory(src/GameWorld/HoldItem/)
#↑↑↑↑↑↑↑↑↑↑↑ ADD YOUR SUBDIRECTORIES HERE ↑↑↑↑↑↑↑↑↑↑↑↑↑

add_executable(
  ${PROJECT_NAME}
  src/main.cpp
)

target_link_libraries(
  ${PROJECT_NAME}
  Framework
  GameWorld
)

target_include_directories(
  ${PROJECT_NAME} 
  PUBLIC 
  src/
  src/Framework/
  src/GameWorld/
)
