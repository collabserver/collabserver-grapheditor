# ------------------------------------------------------------------------------
# Download and build collab-data at cmake time
# Inspired from googletest cmake
# See: https://github.com/google/googletest/tree/master/googletest
# ------------------------------------------------------------------------------

# Alias variables
set(COLLAB_DATA_DIR       "${COLLAB_DEPENDENCIES_DIR}/collabdata")
set(COLLAB_DATA_SOURCES   "${COLLAB_DATA_DIR}/sources")
set(COLLAB_DATA_HEADERS   "${COLLAB_DATA_DIR}/include")
set(COLLAB_DATA_LIB       "${COLLAB_DATA_DIR}/lib")
set(COLLAB_DATA_DOWNLOAD  "${CMAKE_BINARY_DIR}/collabdata-download")
set(COLLAB_DATA_BUILD     "${CMAKE_BINARY_DIR}/collabdata-build")


if(COLLAB_DEPENDENCIES_DOWNLOAD)
    # Create dep folder content
    file(MAKE_DIRECTORY "${COLLAB_DATA_SOURCES}")
    file(MAKE_DIRECTORY "${COLLAB_DATA_HEADERS}")
    file(MAKE_DIRECTORY "${COLLAB_DATA_LIB}")

    # Create Download CMakeLists
    configure_file(
        "${CMAKE_SOURCE_DIR}/CMake/ExternalProjects/CollabData.cmake"
        "${COLLAB_DATA_DOWNLOAD}/CMakeLists.txt")

    # Setup Download (in download folder)
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLAB_DATA_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "CMake step for collabdata failed: ${result}")
    endif()

    # Clone (in source folder)
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLAB_DATA_DOWNLOAD}")
    if(result)
        message(FATAL_ERROR "Build step for collabdata failed: ${result}")
    endif()

    # Build collabdata
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY "${COLLAB_DATA_BUILD}")
    if(result)
        message(FATAL_ERROR "Build step for collabdata failed: ${result}")
    endif()

    # Just to place headers in dependency folder
    file(COPY "${COLLAB_DATA_SOURCES}/include"
         DESTINATION "${COLLAB_DATA_DIR}")
    file(COPY "${COLLAB_DATA_BUILD}/libcollabdata.a"
         DESTINATION "${COLLAB_DATA_LIB}")

elseif(NOT IS_DIRECTORY "${COLLAB_DATA_HEADERS}")
    message("WARNING: collab-data dependency is missing.")
    message("To download it automatically, set -DCOLLAB_DEPENDENCIES_DOWNLOAD=ON")
    message(FATAL_ERROR "Missing dependency...")

elseif(NOT EXISTS "${COLLAB_DATA_LIB}/libcollabdata.a")
    message("WARNING: collab-data dependency build is missing")
    message("To build it automatically, set -DCOLLAB_DEPENDENCIES_BUILD=ON")
    message(FATAL_ERROR "Missing dependency...")
endif()


# Include in project
include_directories("${COLLAB_DATA_HEADERS}")
add_library(collabdata STATIC IMPORTED)
set_property(TARGET collabdata PROPERTY
             IMPORTED_LOCATION "${COLLAB_DATA_LIB}/libcollabdata.a")


