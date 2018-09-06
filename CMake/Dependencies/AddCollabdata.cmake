# ------------------------------------------------------------------------------
# Download and build collab-data at cmake time
# See: https://github.com/google/googletest/tree/master/googletest
# ------------------------------------------------------------------------------

configure_file(
    "${CMAKE_SOURCE_DIR}/CMake/ExternalProjects/Collabdata.cmake"
    "collab-data-crdts-download/CMakeLists.txt")

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/collab-data-crdts-download")
if(result)
    message(FATAL_ERROR "CMake step for collabdata failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/collab-data-crdts-download")
if(result)
    message(FATAL_ERROR "Build step for collabdata failed: ${result}")
endif()

include_directories("${collab_gitmodule_dir}/collab-data-crdts/include")

add_library(collabdata STATIC IMPORTED)
set_property(TARGET collabdata PROPERTY IMPORTED_LOCATION
    "${CMAKE_BINARY_DIR}/collab-data-crdts-build/libcollabdata.a")

