message(STATUS "Building Mvk client")

include_directories("${CMAKE_SOURCE_DIR}/mvk/include")
file(GLOB_RECURSE srcMvk "${CMAKE_SOURCE_DIR}/mvk/src/*.cpp")

add_executable(mvk_poc ${srcMvk})
add_custom_target(runMvk mvk_poc)

target_link_libraries(mvk_poc
    collabclient
    collabcommon
    collabdata
    zmq
    curl
    pthread)


