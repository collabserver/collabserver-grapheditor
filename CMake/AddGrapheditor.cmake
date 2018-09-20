message(STATUS "Building GraphicEditor client")

include_directories("${CMAKE_SOURCE_DIR}/include/")
file(GLOB_RECURSE srcFiles "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(grapheditor ${srcFiles})
add_custom_target(run grapheditor)

target_link_libraries(grapheditor
    collabclient
    collabcommon
    collabdata
    curl
    zmq
    pthread)


# Copy resources folder
set(RESOURCES_SRC "${CMAKE_SOURCE_DIR}/resources/")
set(RESOURCES_BIN "${CMAKE_BINARY_DIR}/resources/")
add_custom_command(
    OUTPUT "${RESOURCES_BIN}"
    DEPENDS "${RESOURCES_SRC}"
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${RESOURCES_SRC} ${RESOURCES_BIN}
)
add_custom_target(copyResources ALL DEPENDS "${RESOURCES_BIN}")
add_dependencies(run copyResources)

