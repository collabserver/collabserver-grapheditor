# ------------------------------------------------------------------------------
# Project collab-common (gitsubmodule)
# ------------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)

project(collab-common-download NONE)

include(ExternalProject)
ExternalProject_Add(collab-common
    SOURCE_DIR          "${collab_gitmodule_dir}/collab-client-interface/gitmodules/collab-common/"
    BINARY_DIR          "${CMAKE_BINARY_DIR}/collab-common-build/"
    INSTALL_COMMAND     ""
    TEST_COMMAND        ""
    CMAKE_ARGS          "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
)


