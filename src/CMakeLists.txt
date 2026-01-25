add_subdirectory(crc)

target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE
        protocol.c
)

target_link_libraries(${CMAKE_PROJECT_NAME}
    PRIVATE
        rp_crc
)