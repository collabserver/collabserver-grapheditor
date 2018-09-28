# ------------------------------------------------------------------------------
# Project collab-client-interface
# ------------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)

project(collab-client-interface-download NONE)

include(ExternalProject)
ExternalProject_Add(collab-client-interface
    GIT_REPOSITORY      "https://github.com/CollabServer/collab-client-interface.git"
    GIT_TAG             "dev"
    SOURCE_DIR          "${COLLAB_CLIENT_SOURCES}"
    BINARY_DIR          "${COLLAB_CLIENT_BUILD}"
    BUILD_COMMAND       ""
    INSTALL_COMMAND     ""
    TEST_COMMAND        ""
    CMAKE_ARGS          "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
                        "-DCOLLAB_DEPENDENCIES_DOWNLOAD=${COLLAB_DEPENDENCIES_DOWNLOAD}"
                        "-DCOLLAB_DEPENDENCIES_DIR=${COLLAB_DEPENDENCIES_DIR}"
)


