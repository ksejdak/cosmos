set(SOURCES
    ../include/os/assert.h
    ../include/os/chain.h
    ../include/os/circular_buffer.h
    ../include/os/list.h
    ../include/os/shared_ptr.h
    ../include/os/stdint.h
    ../include/os/string.h
    ../include/os/unique_ptr.h
    ../include/os/utils.h
	compiler.cpp
    mutex.cpp
    string.cpp
    utils.cpp
)

register_module()
