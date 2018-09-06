# ------------------------------------------------------------------------------
# Download and build collab-client at cmake time
# See: https://github.com/google/googletest/tree/master/googletest
# ------------------------------------------------------------------------------

configure_file(
    "${CMAKE_SOURCE_DIR}/CMake/ExternalProjects/Collabclient.cmake"
    "collab-client-interface-download/CMakeLists.txt")

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/collab-client-interface-download")
if(result)
    message(FATAL_ERROR "CMake step for collabclient failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/collab-client-interface-download")
if(result)
    message(FATAL_ERROR "Build step for collabclient failed: ${result}")
endif()

include_directories("${collab_gitmodule_dir}/collab-client-interface/include")

add_library(collabclient STATIC IMPORTED)
set_property(TARGET collabclient PROPERTY IMPORTED_LOCATION
    "${CMAKE_BINARY_DIR}/collab-client-interface-build/libcollabclient.a")


