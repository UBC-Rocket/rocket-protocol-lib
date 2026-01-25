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