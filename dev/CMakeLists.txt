set(SOURCES
    device_manager.h
    gpio.h
    uart.h
)

set(MODULES
    ${COSMOS_CPU}
)

register_component()
link_target(${COSMOS_FS_PATH})
