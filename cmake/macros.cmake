# Requires: SOURCES
macro(register_executable EXE_NAME)
    message(STATUS "Creating executable [${EXE_NAME}]")

    add_executable(${EXE_NAME} ${SOURCES})
endmacro()

# Requires: COMPONENTS
macro(register_packet)
    set(CURRENT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
    get_filename_component(PACKET ${CURRENT_PATH} NAME)
    message(STATUS "Creating packet [${PACKET}]")

    foreach(COMPONENT ${COMPONENTS})
        add_subdirectory(${COMPONENT})
    endforeach()
endmacro()

# Requires: component.cpp [SOURCES] [MODULES]
macro(register_component)
    set(CURRENT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
    get_filename_component(COMPONENT ${CURRENT_PATH} NAME)
    message(STATUS "Creating component [${COMPONENT}]")

    add_library(${COMPONENT} ${COMPONENT}.cpp ${SOURCES})
    set_property(TARGET ${COMPONENT} PROPERTY FOLDER ${COMPONENT})
    
    foreach(MODULE ${MODULES})
        add_subdirectory(${MODULE})
        set_property(TARGET ${MODULE} PROPERTY FOLDER ${COMPONENT})

        target_link_libraries(${COMPONENT} ${MODULE})
    endforeach()
endmacro()

# Requires: SOURCES
macro(register_module)
    set(CURRENT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
    get_filename_component(MODULE ${CURRENT_PATH} NAME)
    message(STATUS "Creating module [${MODULE}]")

    add_library(${MODULE} ${SOURCES})
endmacro()

macro(link_target TARGET_NAME)
    set(CURRENT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
    get_filename_component(CURRENT_TARGET ${CURRENT_PATH} NAME)
    get_filename_component(LINKED_TARGET ${TARGET_NAME} NAME)

    target_link_libraries(${CURRENT_TARGET} ${LINKED_TARGET})
endmacro()

macro(link_targetEx CURRENT_TARGET LINKED_TARGET_PATH)
    get_filename_component(TARGET_NAME ${LINKED_TARGET_PATH} NAME)
    set(LINKED_TARGET ${TARGET_NAME})

    target_link_libraries(${CURRENT_TARGET} ${LINKED_TARGET})
endmacro()
