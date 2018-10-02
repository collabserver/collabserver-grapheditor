cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)

project(collab-data-crdts-download NONE)

include(ExternalProject)
ExternalProject_Add(collab-data-crdts
    GIT_REPOSITORY      "https://github.com/CollabServer/collab-data-crdts.git"
    GIT_TAG             "dev"
    SOURCE_DIR          "${COLLAB_DATA_SOURCES}"
    BINARY_DIR          "${COLLAB_DATA_BUILD}"
    BUILD_COMMAND       ""
    INSTALL_COMMAND     ""
    TEST_COMMAND        ""
    CMAKE_ARGS          "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
                        "-DCOLLAB_DEPENDENCIES_DOWNLOAD=${COLLAB_DEPENDENCIES_DOWNLOAD}"
                        "-DCOLLAB_DEPENDENCIES_DIR=${COLLAB_DEPENDENCIES_DIR}"
)


