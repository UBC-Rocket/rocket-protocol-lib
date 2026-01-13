cmake_minimum_required(VERSION 3.22)

project(
    rocket-protocol
    DESCRIPTION "UBC Rocket shared protocol library"
    LANGUAGES C
)

# Generate compile_commands.json for development tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define our library target
add_library(rocket-protocol)
add_library("rocket-protocol::protocol" ALIAS rocket-protocol)

set_property(
    TARGET rocket-protocol
    PROPERTY
        C_EXTENSIONS OFF
)

target_include_directories(rocket-protocol
    PUBLIC
        include
)

add_subdirectory(src)
