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
    pthread
    curl)


# Tests MVK
file(GLOB_RECURSE srcMvk_tests 
    "${CMAKE_SOURCE_DIR}/mvk/tests/Test_MVKWrapper.cpp"
    "${CMAKE_SOURCE_DIR}/mvk/src/MVKWrapper.cpp"
    "${CMAKE_SOURCE_DIR}/mvk/src/UuidGenerator.cpp"
    )

add_executable(mvk_tests ${srcMvk_tests})
add_custom_target(runMvkTests mvk_tests)

target_link_libraries(mvk_tests
    collabclient
    collabcommon
    collabdata
    zmq
    pthread
    curl)

