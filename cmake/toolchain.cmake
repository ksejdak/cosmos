macro(set_toolchain ARCH)
    if(${ARCH} STREQUAL "arm")
        # Set toolchain for target.
        set(CMAKE_C_COMPILER "arm-none-eabi-gcc")
        set(CMAKE_CXX_COMPILER "arm-none-eabi-g++")
        set(CMAKE_ASM_COMPILER "arm-none-eabi-as")

        set(COMMON_FLAGS "-mcpu=cortex-a8 -march=armv7-a -mthumb -mfpu=neon -mfloat-abi=hard -fno-common -ffunction-sections -fdata-sections -static -lgcc -Wall -Wextra -nostartfiles -nostdinc -nostdlib")
        set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)
        set(CMAKE_EXECUTABLE_SUFFIX ".elf")

        # Set linker script.
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${COSMOS_BOARD_PATH}/${COSMOS_TARGET}.ld")
        set(CMAKE_EXE_LINKER_FLAGS_RELEASE ${CMAKE_EXE_LINKER_FLAGS_RELEASE} "-s")

        # Set C compilation flags.
        set(CMAKE_C_FLAGS "${COMMON_FLAGS} -std=c11")
        set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
        set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O2 -Werror")

        # Set C++ compilation flags.
        set(CMAKE_CXX_FLAGS "${COMMON_FLAGS} -std=c++14")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions -fno-unwind-tables")    # Disable C++ exceptions support, because it requires libc.
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")                             # Disable C++ run time information, because it requires libc.
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-threadsafe-statics")               # Do not produce code to initialize statics in thread-safe way.
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -Werror")
    endif()

    string(REGEX REPLACE ";" " " CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
    string(REGEX REPLACE ";" " " CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}")
    string(REGEX REPLACE ";" " " CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")
    string(REGEX REPLACE ";" " " CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    string(REGEX REPLACE ";" " " CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
    string(REGEX REPLACE ";" " " CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    string(REGEX REPLACE ";" " " CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
    string(REGEX REPLACE ";" " " CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE}")
    
    message(STATUS "Setting toolchain to:")
    message(STATUS "  C compiler         : ${CMAKE_C_COMPILER}")
    message(STATUS "  C++ compiler       : ${CMAKE_CXX_COMPILER}")
    message(STATUS "  assembler          : ${CMAKE_ASM_COMPILER}")
    message(STATUS "  C compiler flags   : ${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_DEBUG}")
    message(STATUS "  C++ compiler flags : ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")
endmacro()
