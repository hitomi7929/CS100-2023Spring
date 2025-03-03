# Install script for directory: C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/third_party/freeglut

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/out/build/x64-Debug/lib/freeglut.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/out/build/x64-Debug/bin/freeglut.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/out/build/x64-Debug/bin/freeglut.pdb")
  endif(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/out/build/x64-Debug/lib/freeglut_static.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/GL" TYPE FILE FILES
    "C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/third_party/freeglut/include/GL/freeglut.h"
    "C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/third_party/freeglut/include/GL/freeglut_ucall.h"
    "C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/third_party/freeglut/include/GL/freeglut_ext.h"
    "C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/third_party/freeglut/include/GL/freeglut_std.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE RENAME "freeglut.pc" FILES "C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/out/build/x64-Debug/freeglut.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/FreeGLUT/FreeGLUTTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/FreeGLUT/FreeGLUTTargets.cmake"
         "C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/out/build/x64-Debug/freeglut/CMakeFiles/Export/6f3d6babffe806515ac5156322d25f7d/FreeGLUTTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/FreeGLUT/FreeGLUTTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/FreeGLUT/FreeGLUTTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/FreeGLUT" TYPE FILE FILES "C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/out/build/x64-Debug/freeglut/CMakeFiles/Export/6f3d6babffe806515ac5156322d25f7d/FreeGLUTTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/FreeGLUT" TYPE FILE FILES "C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/out/build/x64-Debug/freeglut/CMakeFiles/Export/6f3d6babffe806515ac5156322d25f7d/FreeGLUTTargets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/FreeGLUT" TYPE FILE FILES
    "C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/out/build/x64-Debug/freeglut/FreeGLUT/FreeGLUTConfig.cmake"
    "C:/Academic_Files/2023_Spring/CS100_YuexinMa/Homeworks/hw8/hw8_2/attachments/out/build/x64-Debug/freeglut/FreeGLUT/FreeGLUTConfigVersion.cmake"
    )
endif()

