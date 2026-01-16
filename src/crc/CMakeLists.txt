add_library(rp_crc)

set_property(
    TARGET rp_crc
    PROPERTY
        C_STANDARD 11
        C_STANDARD_REQUIRED ON
        C_EXTENSIONS OFF
)

target_sources(rp_crc
    PRIVATE
        crc16.c
)

target_link_libraries(rp_crc
    PUBLIC
        rp_library_interface
)