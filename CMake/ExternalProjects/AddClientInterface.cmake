# ------------------------------------------------------------------------------
# Project collab-client-interface (gitsubmodule)
# ------------------------------------------------------------------------------
include(ExternalProject)
ExternalProject_Add(collab-client-interface
    SOURCE_DIR          "${git_submodule_dir}/collab-client-interface/"
    BINARY_DIR          "${CMAKE_BINARY_DIR}/collab-client-interface-build"
    INSTALL_COMMAND     ""
    TEST_COMMAND        ""
)

ExternalProject_Get_Property(collab-client-interface binary_dir)
add_library(client_interface STATIC IMPORTED)
set_property(TARGET client_interface PROPERTY IMPORTED_LOCATION
    "${binary_dir}/libclient_interface.a")


