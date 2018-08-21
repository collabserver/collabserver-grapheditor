# ------------------------------------------------------------------------------
# Project collab-data-crdts (gitsubmodule)
# ------------------------------------------------------------------------------

include(ExternalProject)
ExternalProject_Add(collab-data-crdts
    SOURCE_DIR          "${collab_gitmodule_dir}/collab-data-crdts/"
    BINARY_DIR          "${CMAKE_BINARY_DIR}/collab-data-crdts-build"
    INSTALL_COMMAND     ""
    TEST_COMMAND        ""
    CMAKE_ARGS          "-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
)

ExternalProject_Get_Property(collab-data-crdts binary_dir)
add_library(collabdata STATIC IMPORTED)
set_property(TARGET collabdata PROPERTY IMPORTED_LOCATION
    "${binary_dir}/libcollabdata.a")


