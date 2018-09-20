cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)
project(collab-grapheditor)

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message(FATAL_ERROR "in-source build not allowed. Use another directory.")
endif()


# ------------------------------------------------------------------------------
# Various / Dependencies
# ------------------------------------------------------------------------------
set(collab_gitmodule_dir "${CMAKE_SOURCE_DIR}/gitmodules/")

include("CMake/AddCompilerFlags.cmake")

include("CMake/Dependencies/AddCollabdata.cmake")
include("CMake/Dependencies/AddCollabclient.cmake")
include("CMake/Dependencies/AddCollabcommon.cmake")


# ------------------------------------------------------------------------------
# GraphEditor Executable
# ------------------------------------------------------------------------------
message(STATUS "Build GraphEditor client")
include("CMake/AddGrapheditor.cmake")


