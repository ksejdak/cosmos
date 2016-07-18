set(SOURCES
    ARMProcessor.cpp
    MMU.cpp
    Startup.s
)

register_module()

link_targetEx(${COSMOS_ARCH} ${COSMOS_BOARD_PATH})
