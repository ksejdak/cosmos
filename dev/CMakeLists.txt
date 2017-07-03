set(SOURCES
    device_manager.h
    gpio.cpp
    uart.cpp
)

set(MODULES
    ${COSMOS_CPU}
)

register_component()
link_target(${COSMOS_FS_PATH})
