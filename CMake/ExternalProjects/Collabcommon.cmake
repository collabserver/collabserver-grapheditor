# ------------------------------------------------------------------------------
# Project collab-common (gitsubmodule)
# ------------------------------------------------------------------------------

include(ExternalProject)
ExternalProject_Add(collab-common
    SOURCE_DIR          "${collab_gitmodule_dir}/collab-client-interface/gitmodules/collab-common/"
    BINARY_DIR          "${CMAKE_BINARY_DIR}/collab-common-build/"
    INSTALL_COMMAND     ""
    TEST_COMMAND        ""
    CMAKE_ARGS          "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
)

add_library(collabcommon STATIC IMPORTED)
ExternalProject_Get_Property(collab-common BINARY_DIR)
set_property(TARGET collabcommon
    PROPERTY IMPORTED_LOCATION "${BINARY_DIR}/libcollabcommon.a")
