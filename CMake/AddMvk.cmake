message(STATUS "Building Mvk executable")

include_directories("${CMAKE_SOURCE_DIR}/mvk/include")
include_directories("${collab_gitmodule_dir}/collab-data-crdts/include")
include_directories("${collab_gitmodule_dir}/collab-client-interface/include")

file(GLOB_RECURSE srcMvk "${CMAKE_SOURCE_DIR}/mvk/src/*.cpp")

add_executable(mvk_poc ${srcMvk})
add_dependencies(mvk_poc collab-client-interface)
add_custom_target(runMvk mvk_poc)

target_link_libraries(mvk_poc collab_client curlpp)


