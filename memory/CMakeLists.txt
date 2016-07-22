set(SOURCES
	allocator.cpp
	buddy_allocator.cpp
    page.cpp
    pagepool.h
    pagepool_dynamic.cpp
    pagepool_static.cpp
    regions.cpp
)


register_module()

link_target(${COSMOS_LIB_PATH})
