# Install script for directory: /home/ubuntu/arduinobot-tutorial/L5-Digital-Twin-with-URDF/arduinobot_ws/src/arduinobot_controller

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/ubuntu/arduinobot-tutorial/L5-Digital-Twin-with-URDF/arduinobot_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/ubuntu/arduinobot-tutorial/L5-Digital-Twin-with-URDF/arduinobot_ws/build/arduinobot_controller/catkin_generated/installspace/arduinobot_controller.pc")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/arduinobot_controller/cmake" TYPE FILE FILES
    "/home/ubuntu/arduinobot-tutorial/L5-Digital-Twin-with-URDF/arduinobot_ws/build/arduinobot_controller/catkin_generated/installspace/arduinobot_controllerConfig.cmake"
    "/home/ubuntu/arduinobot-tutorial/L5-Digital-Twin-with-URDF/arduinobot_ws/build/arduinobot_controller/catkin_generated/installspace/arduinobot_controllerConfig-version.cmake"
    )
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/arduinobot_controller" TYPE FILE FILES "/home/ubuntu/arduinobot-tutorial/L5-Digital-Twin-with-URDF/arduinobot_ws/src/arduinobot_controller/package.xml")
endif()
