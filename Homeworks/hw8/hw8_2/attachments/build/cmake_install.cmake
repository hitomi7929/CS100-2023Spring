# Install script for directory: C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/PvZ")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/build/src/Framework/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/build/src/GameWorld/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/build/src/GameObject/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/build/src/GameObject/Sun/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/build/src/GameObject/PlantingSpot/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/build/src/GameObject/Seed/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/build/src/GameObject/Plant/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/build/src/GameObject/Zombie/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/build/src/GameObject/CooldownMask/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/build/src/GameObject/Shovel/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/build/src/GameObject/Bullet/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/build/src/GameObject/Object/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/build/src/GameWorld/HoldItem/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
