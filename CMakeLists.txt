cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)
project(collab-poc)

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message(FATAL_ERROR "in-source build not allowed. Use another directory.")
endif()


# ------------------------------------------------------------------------------
# Various / Dependencies
# ------------------------------------------------------------------------------
set(dependency_dir "${CMAKE_SOURCE_DIR}/bin/")
set(git_submodule_dir "${CMAKE_SOURCE_DIR}/gitmodules/")

include("CMake/ExternalProjects/AddClientInterface.cmake")


# ------------------------------------------------------------------------------
# Executable
# ------------------------------------------------------------------------------
include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories("${git_submodule_dir}/collab-data-crdts/include")
include_directories("${git_submodule_dir}/collab-client-interface/include")

file(GLOB_RECURSE srcFilesPOC "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(client_poc ${srcFilesPOC})
add_dependencies(client_poc collab-client-interface)
add_custom_target(runClientPOC client_poc)

target_link_libraries(client_poc "zmq" client_interface)


