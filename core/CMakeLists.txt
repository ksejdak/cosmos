set(SOURCES
	kernel.cpp
    main.cpp
)

register_executable(${PROJECT_NAME})

link_targetEx(${PROJECT_NAME} ${COSMOS_HAL_PATH})
