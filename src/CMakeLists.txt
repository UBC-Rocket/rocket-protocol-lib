add_subdirectory(crc)
add_subdirectory(cobs)

target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE
        codec.c
)

target_link_libraries(${CMAKE_PROJECT_NAME}
    PRIVATE
        rp_crc
        rp_cobs
)