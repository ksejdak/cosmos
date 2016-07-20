set(SOURCES
    armcortex_a.cpp
    mmu.cpp
    startup.s
)

register_module()

link_targetEx(${COSMOS_ARCH} ${COSMOS_BOARD_PATH})
