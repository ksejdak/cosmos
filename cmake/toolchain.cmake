macro(set_toolchain ARCH)
    if(${ARCH} STREQUAL "arm")
        # Set toolchain for target.
        set(CMAKE_C_COMPILER "arm-none-eabi-gcc")
        set(CMAKE_CXX_COMPILER "arm-none-eabi-g++")
        set(CMAKE_ASM_COMPILER "arm-none-eabi-as")

        set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-mcpu=cortex-m4 -march=armv7e-m -mthumb -mfpu=fpv4-sp-d16 -fno-common -ffunction-sections -fdata-sections -static -nostdlib -lgcc")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_C_FLAGS}")
        set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)
        set(CMAKE_EXECUTABLE_SUFFIX ".elf")

        # Set linker script.
        set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-T ${COSMOS_BOARD_PATH}/${COSMOS_TARGET}.ld")
        set(CMAKE_EXE_LINKER_FLAGS_RELEASE ${CMAKE_EXE_LINKER_FLAGS_RELEASE} "-s")

        # Set compilation flags.
        set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++14 -Wall -Wextra")
        set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG} "-O0")
        set(CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE} "-O2 -Werror")

    endif()

    string(REGEX REPLACE ";" " " CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    string(REGEX REPLACE ";" " " CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
    string(REGEX REPLACE ";" " " CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    string(REGEX REPLACE ";" " " CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
    string(REGEX REPLACE ";" " " CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE}")
    
    message(STATUS "Setting toolchain to:")
    message(STATUS "  compiler       : ${CMAKE_CXX_COMPILER}")
    message(STATUS "  assembler      : ${CMAKE_ASM_COMPILER}")
    message(STATUS "  compiler flags : ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")
endmacro()
