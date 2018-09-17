cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)
project(collab-poc)

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
# GraphEditor
# ------------------------------------------------------------------------------
option(collab_graphiceditor "Build GraphicEditor client" ON)

if(collab_graphiceditor)
    message(STATUS "Build GraphicEditor client")
    include("CMake/AddGraphiceditor.cmake")
endif()


# ------------------------------------------------------------------------------
# Mvk
# ------------------------------------------------------------------------------
option(collab_mvk "Build Mvk database client" ON)

if(collab_mvk)
    message(STATUS "Build Mvk db client")
    include("CMake/AddMvk.cmake")
endif()

