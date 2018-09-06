# ------------------------------------------------------------------------------
# Download and build collab-common at cmake time
# See: https://github.com/google/googletest/tree/master/googletest
# ------------------------------------------------------------------------------

configure_file(
    "${CMAKE_SOURCE_DIR}/CMake/ExternalProjects/Collabcommon.cmake"
    "collab-common-download/CMakeLists.txt")

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/collab-common-download")
if(result)
    message(FATAL_ERROR "CMake step for collabcommon failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/collab-common-download")
if(result)
    message(FATAL_ERROR "Build step for collabcommon failed: ${result}")
endif()

add_library(collabcommon STATIC IMPORTED)
set_property(TARGET collabcommon PROPERTY IMPORTED_LOCATION
    "${CMAKE_BINARY_DIR}/collab-common-build/libcollabcommon.a")

