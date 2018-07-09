message(STATUS "Building GraphicEditor executable")

include_directories("${CMAKE_SOURCE_DIR}/grapheditor/include")
include_directories("${collab_gitmodule_dir}/collab-data-crdts/include")
include_directories("${collab_gitmodule_dir}/collab-client-interface/include")

file(GLOB_RECURSE srcGrapheditor "${CMAKE_SOURCE_DIR}/grapheditor/src/*.cpp")

add_executable(grapheditor_poc ${srcGrapheditor})
add_dependencies(grapheditor_poc collab-data-crdts)
add_dependencies(grapheditor_poc collab-client-interface)
add_custom_target(runGrapheditor grapheditor_poc)

target_link_libraries(grapheditor_poc collab_client collabdata)
