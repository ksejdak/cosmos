set(SOURCES
	allocator.cpp
	buddy_allocator.cpp
    page.cpp
    pagepool.cpp
    pagepool_dynamic.cpp
    pagepool_static.cpp
    regions.cpp
)


register_module()

link_target(${COSMOS_LIB_PATH})
