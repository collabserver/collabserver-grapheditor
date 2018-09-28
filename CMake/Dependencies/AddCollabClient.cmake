# ------------------------------------------------------------------------------
# Download and build collab-client at cmake time
# Inspired from googletest cmake
# See: https://github.com/google/googletest/tree/master/googletest
# ------------------------------------------------------------------------------

# Alias variables
set(COLLAB_CLIENT_DIR       "${COLLAB_DEPENDENCIES_DIR}/collabclient")
set(COLLAB_CLIENT_SOURCES   "${COLLAB_CLIENT_DIR}/sources")
set(COLLAB_CLIENT_HEADERS   "${COLLAB_CLIENT_DIR}/include")
set(COLLAB_CLIENT_LIB       "${COLLAB_CLIENT_DIR}/lib")
set(COLLAB_CLIENT_DOWNLOAD  "${CMAKE_BINARY_DIR}/collabclient-download")
set(COLLAB_CLIENT_BUILD     "${CMAKE_BINARY_DIR}/collabclient-build")


if(COLLAB_DEPENDENCIES_DOWNLOAD)
    # Create dep folder content
    file(MAKE_DIRECTORY "${COLLAB_CLIENT_SOURCES}")
    file(MAKE_DIRECTORY "${COLLAB_CLIENT_HEADERS}")
    file(MAKE_DIRECTORY "${COLLAB_CLIENT_LIB}")

    # Create Download CMakeLists
    configure_file(
        "${CMAKE_SOURCE_DIR}/CMake/ExternalProjects/CollabClient.cmake"
        "${COLLAB_CLIENT_DOWNLOAD}/CMakeLists.txt")

    # Setup Download (in download folder)
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLAB_CLIENT_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "CMake step for collabclient failed: ${result}")
    endif()

    # Clone (in source folder)
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLAB_CLIENT_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "Build step for collabclient failed: ${result}")
    endif()

    # Build collabclient
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLAB_CLIENT_BUILD}")
    if(result)
        message(FATAL_ERROR "Build step for collabclient failed: ${result}")
    endif()

    # Place headers and lib in respective dependency folder
    file(COPY "${COLLAB_CLIENT_SOURCES}/include"
         DESTINATION "${COLLAB_CLIENT_DIR}")
    file(COPY "${COLLAB_CLIENT_BUILD}/libcollabclient.a"
         DESTINATION "${COLLAB_CLIENT_LIB}")

elseif(NOT IS_DIRECTORY "${COLLAB_CLIENT_HEADERS}")
    message("WARNING: collab-client-interface dependency is missing.")
    message("To download it automatically, set -DCOLLAB_DEPENDENCIES_DOWNLOAD=ON")
    message(FATAL_ERROR "Missing dependency...")

elseif(NOT EXISTS "${COLLAB_CLIENT_LIB}/libcollabclient.a")
    message("WARNING: collab-client-interface dependency is not built")
    message("To build it automatically, set -DCOLLAB_DEPENDENCIES_BUILD=ON")
    message(FATAL_ERROR "Missing dependency...")
endif()


# Include in project
include_directories("${COLLAB_CLIENT_HEADERS}")
add_library(collabclient STATIC IMPORTED)
set_property(TARGET collabclient PROPERTY
             IMPORTED_LOCATION "${COLLAB_CLIENT_LIB}/libcollabclient.a")


