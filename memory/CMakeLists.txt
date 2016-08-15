set(SOURCES
	allocator.cpp
	buddy_allocator.cpp
    page.cpp
    pagepool.cpp
    regions.cpp
)

register_module()

link_target(${COSMOS_LIB_PATH})
