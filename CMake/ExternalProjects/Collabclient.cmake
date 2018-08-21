# ------------------------------------------------------------------------------
# Project collab-client-interface (gitsubmodule)
# ------------------------------------------------------------------------------
include(ExternalProject)
ExternalProject_Add(collab-client-interface
    SOURCE_DIR          "${collab_gitmodule_dir}/collab-client-interface/"
    BINARY_DIR          "${CMAKE_BINARY_DIR}/collab-client-interface-build"
    INSTALL_COMMAND     ""
    TEST_COMMAND        ""
)

ExternalProject_Get_Property(collab-client-interface binary_dir)
add_library(collabclient STATIC IMPORTED)
set_property(TARGET collabclient PROPERTY IMPORTED_LOCATION
    "${binary_dir}/libcollabclient.a")


