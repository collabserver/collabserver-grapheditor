cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)
project(collab-poc)

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message(FATAL_ERROR "in-source build not allowed. Use another directory.")
endif()


# ------------------------------------------------------------------------------
# Various / Dependencies
# ------------------------------------------------------------------------------
set(collab_dependency_dir "${CMAKE_SOURCE_DIR}/bin/")
set(collab_gitmodule_dir "${CMAKE_SOURCE_DIR}/gitmodules/")

include("CMake/AddCompilerFlags.cmake")
include("CMake/ExternalProjects/AddCollabClient.cmake")


# ------------------------------------------------------------------------------
# Executable GraphEditor (Client)
# ------------------------------------------------------------------------------
message(STATUS "Building poc client executable")

include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories("${collab_gitmodule_dir}/collab-data-crdts/include")
include_directories("${collab_gitmodule_dir}/collab-client-interface/include")

file(GLOB_RECURSE srcGrapheditor "${CMAKE_SOURCE_DIR}/grapheditor/src/*.cpp")

add_executable(grapheditor_poc ${srcGrapheditor})
add_dependencies(grapheditor_poc collab-client-interface)
add_custom_target(runGrapheditor grapheditor_poc)

target_link_libraries(grapheditor_poc "zmq" collab_client)


# ------------------------------------------------------------------------------
# Executable database
# ------------------------------------------------------------------------------
message(STATUS "Building poc database executable")

include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories("${collab_gitmodule_dir}/collab-data-crdts/include")
include_directories("${collab_gitmodule_dir}/collab-client-interface/include")

file(GLOB_RECURSE srcMvk "${CMAKE_SOURCE_DIR}/mvk/src/*.cpp")

add_executable(mvk_poc ${srcMvk})
add_dependencies(mvk_poc collab-client-interface)
add_custom_target(runMvk mvk_poc)

target_link_libraries(mvk_poc "zmq" collab_client)


