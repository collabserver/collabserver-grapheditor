# ------------------------------------------------------------------------------
# Project collab-client-interface (gitsubmodule)
# ------------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)

project(collab-client-interface-download NONE)

include(ExternalProject)
ExternalProject_Add(collab-client-interface
    SOURCE_DIR          "${collab_gitmodule_dir}/collab-client-interface/"
    BINARY_DIR          "${CMAKE_BINARY_DIR}/collab-client-interface-build/"
    INSTALL_COMMAND     ""
    TEST_COMMAND        ""
    CMAKE_ARGS          "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
)


