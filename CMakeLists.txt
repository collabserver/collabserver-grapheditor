cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)
project(collabserver-grapheditor)
message(STATUS "Building project ${PROJECT_NAME}")

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message(FATAL_ERROR "in-source build not allowed. Use another directory.")
endif()


# Compiler Flags
message(STATUS "Detected Operating System: ${CMAKE_SYSTEM_NAME}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    message(WARNING "No CMAKE_BUILD_TYPE set for ${PROJECT_NAME}: uses default Release")
    message(WARNING "Available build types: Debug Release RelWithDebInfo MinSizeRel")
    set(CMAKE_BUILD_TYPE Release)
endif()
message(STATUS "CMAKE_BUILD_TYPE for ${PROJECT_NAME}: ${CMAKE_BUILD_TYPE}")


# Dependencies
message(STATUS "Adding dependencies for ${PROJECT_NAME}")

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/cJSON-1.7.14")
include_directories("${PROJECT_SOURCE_DIR}/extern/cJSON-1.7.14")

add_subdirectory("${PROJECT_SOURCE_DIR}/gitmodules/collabserver-client")
include_directories("${PROJECT_SOURCE_DIR}/gitmodules/collabserver-client/include")

add_subdirectory("${PROJECT_SOURCE_DIR}/gitmodules/collabserver-datatypes")
include_directories("${PROJECT_SOURCE_DIR}/gitmodules/collabserver-datatypes/include")

include_directories("${PROJECT_SOURCE_DIR}/extern/msgpack-c-3.3.0/include") # Header only


# GraphEditor Executable
message(STATUS "Building GraphEditor executable")
include_directories("${PROJECT_SOURCE_DIR}/src/")
file(GLOB_RECURSE srcFilesExecutable "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_executable(${PROJECT_NAME}-exe ${srcFilesExecutable})
target_link_libraries(${PROJECT_NAME}-exe collabserver-client-lib cjson curl)
add_custom_target(run ${PROJECT_NAME}-exe)


# Copy resources folder
set(RESOURCES_SRC "${PROJECT_SOURCE_DIR}/resources/")
set(RESOURCES_BIN "${PROJECT_BINARY_DIR}/resources/")
add_custom_command(
    OUTPUT "${RESOURCES_BIN}"
    DEPENDS "${RESOURCES_SRC}"
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${RESOURCES_SRC} ${RESOURCES_BIN}
)
add_custom_target(copyResources ALL DEPENDS "${RESOURCES_BIN}")
add_dependencies(run copyResources)


# Tests
option(COLLABSERVER_GRAPHEDITOR_TESTS "Build Tests" OFF)
if(COLLABSERVER_GRAPHEDITOR_TESTS)
    message(STATUS "Build tests for ${PROJECT_NAME}")
    enable_testing()

    include_directories("${PROJECT_SOURCE_DIR}/include/")
    file(GLOB_RECURSE srcFilesTests "${PROJECT_SOURCE_DIR}/tests/*.cpp")
    file(GLOB_RECURSE srcFilesSimpleGraph "${PROJECT_SOURCE_DIR}/src/simplegraph/*.cpp")
    add_executable(${PROJECT_NAME}-tests ${srcFilesTests} ${srcFilesSimpleGraph})

    # Googletest dependency
    include_directories("${PROJECT_SOURCE_DIR}/extern/googletest/googletest/include/")
    add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest-1.10.0")
    target_link_libraries(${PROJECT_NAME}-tests gtest)

    # Lib dependency
    target_link_libraries(${PROJECT_NAME}-tests collabserver-client-lib cjson curl)

    # Tests target
    add_test(NAME googletests COMMAND ${PROJECT_NAME}-tests)
    add_custom_target(runTests ${PROJECT_NAME}-tests)

    # TODO Temporary disabled
    # Add simple test for Mvk (These are more like examples, rather than actual Unit Tests)
    #file(GLOB_RECURSE srcFilesTestsMvk "${PROJECT_SOURCE_DIR}/tests/mvk/Test_MvkWrapper.cpp"
    #                                   "${PROJECT_SOURCE_DIR}/src/mvk/MvkWrapper.cpp"
    #                                   "${PROJECT_SOURCE_DIR}/src/utils/utils.cpp")
    #add_executable(${PROJECT_NAME}-testsMvk ${srcFilesTestMvk})
    #target_link_libraries(${PROJECT_NAME}-testsMvk collabserver-client-lib cjson curl)
endif()
