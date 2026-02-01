add_library(rp_cobs)

set_property(
    TARGET rp_cobs
    PROPERTY
        C_STANDARD 11
        C_STANDARD_REQUIRED ON
        C_EXTENSIONS OFF
)

target_sources(rp_cobs
    PRIVATE
        cobs.c
)

target_link_libraries(rp_cobs
    PUBLIC
        rp_library_interface
)