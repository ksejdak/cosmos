set(SOURCES
    board.cpp
)

set(MODULES
    ${COSMOS_TARGET}
)

register_component()
link_target(${COSMOS_DEV_PATH})
