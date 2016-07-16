set(SOURCES
    Startup.s
    SystemInit.cpp
)

register_module()

link_targetEx(${COSMOS_ARCH} ${COSMOS_BOARD_PATH})
