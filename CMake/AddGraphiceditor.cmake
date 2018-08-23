message(STATUS "Building GraphicEditor client")

include_directories("${CMAKE_SOURCE_DIR}/grapheditor/include")
include_directories("${collab_gitmodule_dir}/collab-data-crdts/include")
include_directories("${collab_gitmodule_dir}/collab-client-interface/include")

file(GLOB_RECURSE srcGrapheditor "${CMAKE_SOURCE_DIR}/grapheditor/src/*.cpp")

add_executable(grapheditor_poc ${srcGrapheditor})
add_dependencies(grapheditor_poc collab-data-crdts)
add_dependencies(grapheditor_poc collab-common)
add_dependencies(grapheditor_poc collab-client-interface)
add_custom_target(runGrapheditor grapheditor_poc)

target_link_libraries(grapheditor_poc collabclient collabcommon collabdata zmq)


# Copy grapheditor resources folder
set(RESOURCES_SRC "${CMAKE_SOURCE_DIR}/grapheditor/resources/")
set(RESOURCES_BIN "${CMAKE_BINARY_DIR}/resources/")
add_custom_command(
    OUTPUT "${RESOURCES_BIN}"
    DEPENDS "${RESOURCES_SRC}"
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${RESOURCES_SRC} ${RESOURCES_BIN}
)
add_custom_target(copyGrapheditorResources ALL DEPENDS "${RESOURCES_BIN}")
add_dependencies(runGrapheditor copyGrapheditorResources)

