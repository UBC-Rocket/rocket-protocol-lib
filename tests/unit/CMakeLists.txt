find_package(unity REQUIRED)

function(add_unity_test)
    cmake_parse_arguments(arg
        ""
        "NAME"
        "SOURCES;LIBRARIES"
        ${ARGN}
    )

    set(test_target "test_${arg_NAME}")

    add_executable(${test_target})

    target_sources(${test_target}
        PRIVATE
            ${arg_SOURCES}
    )

    target_link_libraries(${test_target}
        PRIVATE
            unity::framework
            ${arg_LIBRARIES}
    )

    add_test(
        NAME ${arg_NAME}
        COMMAND ${test_target}
    )
endfunction()

add_unity_test(
    NAME "crc16"
    SOURCES
        crc/test_crc16.c
    LIBRARIES
        rp_crc
)

add_unity_test(
    NAME "cobs_encode"
    SOURCES
        cobs/test_cobs_encode.c
    LIBRARIES
        rp_cobs
)

add_unity_test(
    NAME "cobs_decode"
    SOURCES
        cobs/test_cobs_decode.c
    LIBRARIES
        rp_cobs
)

add_unity_test(
    NAME "cobs_get_max_encoded_size"
    SOURCES
        cobs/test_cobs_get_max_encoded_size.c
    LIBRARIES
        rp_cobs
)