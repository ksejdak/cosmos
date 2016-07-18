#################################################################################################################
# CMAKE SETTINGS
#################################################################################################################

# Required cmake version.
cmake_minimum_required(VERSION 3.5.1)

# Additional user defined macros.
include(${CMAKE_SOURCE_DIR}/cmake/toolchain.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/macros.cmake)

#################################################################################################################
# PROJECT SETTINGS
#################################################################################################################

set(COSMOS_ARCH "arm")
set(COSMOS_TARGET "beaglebone-black")
set(PROJECT_NAME "cosmos")
project(${PROJECT_NAME} CXX C ASM)

# Project paths.
set(COSMOS_BOARD_PATH ${CMAKE_SOURCE_DIR}/board/${COSMOS_TARGET})
set(COSMOS_CORE_PATH ${CMAKE_SOURCE_DIR}/core)
set(COSMOS_HAL_PATH ${CMAKE_SOURCE_DIR}/hal/${COSMOS_ARCH})

#################################################################################################################
# TOOLCHAIN SETTINGS
#################################################################################################################

set(CMAKE_BUILD_TYPE Debug)
set_toolchain(${COSMOS_ARCH})

# Set common build options.
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/${COSMOS_ARCH}-${COSMOS_TARGET})

# List project configuration.
message(STATUS "Project configuration:")
message(STATUS "  Architecture : " ${COSMOS_ARCH})
message(STATUS "  Target       : " ${COSMOS_TARGET})
message(STATUS "  Build type   : " ${CMAKE_BUILD_TYPE})

#################################################################################################################
# OTHER SETTINGS
#################################################################################################################

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include_directories(include)
include_directories(.)

set(COMPONENTS
    board
    core
    hal
)

register_packet()
