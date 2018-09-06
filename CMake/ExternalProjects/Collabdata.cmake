# ------------------------------------------------------------------------------
# Project collab-data-crdts (gitsubmodule)
# ------------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)

project(collab-data-crdts-download NONE)

include(ExternalProject)
ExternalProject_Add(collab-data-crdts
    SOURCE_DIR          "${collab_gitmodule_dir}/collab-data-crdts/"
    BINARY_DIR          "${CMAKE_BINARY_DIR}/collab-data-crdts-build/"
    INSTALL_COMMAND     ""
    TEST_COMMAND        ""
    CMAKE_ARGS          "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE};-Dcollab_custom=on"
)


