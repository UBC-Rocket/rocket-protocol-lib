cmake_minimum_required(VERSION 3.22)

project(
    rocket-protocol
    DESCRIPTION "UBC Rocket shared protocol library"
    LANGUAGES C
)

option(ROCKET_PROTOCOL_BUILD_TESTS "Build tests for the rocket protocol library" OFF)

# Generate compile_commands.json for development tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Linkable interface library to share common properties
add_library(rp_library_interface INTERFACE)

target_include_directories(rp_library_interface
    INTERFACE
        include
)

# Define our library target
add_library(rocket-protocol)
add_library("rocket-protocol::protocol" ALIAS rocket-protocol)

set_property(
    TARGET rocket-protocol
    PROPERTY
        C_STANDARD 11
        C_STANDARD_REQUIRED ON
        C_EXTENSIONS OFF
)

target_include_directories(rocket-protocol
    PUBLIC
        rp_library_interface
)

add_subdirectory(src)

if(ROCKET_PROTOCOL_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
