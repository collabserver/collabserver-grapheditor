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
add_subdirectory("${PROJECT_SOURCE_DIR}/gitmodules/collabserver-client")
add_subdirectory("${PROJECT_SOURCE_DIR}/gitmodules/collabserver-datatypes")


# GraphEditor Executable
message(STATUS "Building GraphEditor executable")

include_directories("${PROJECT_SOURCE_DIR}/include/")
file(GLOB_RECURSE srcFiles "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_executable(${PROJECT_NAME}-exe ${srcFiles})
add_custom_target(run ${PROJECT_NAME}-exe)
target_link_libraries(${PROJECT_NAME}-exe collabclient curl)


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


# TODO Reintegrate the tests
# Add simple test (This is kind of temporary. These are not actual unit test yet)
#file(GLOB_RECURSE srcFilesTest "${CMAKE_SOURCE_DIR}/tests/mvk/Test_MvkWrapper.cpp"
#                               "${CMAKE_SOURCE_DIR}/src/mvk/MvkWrapper.cpp"
#                               "${CMAKE_SOURCE_DIR}/src/utils/utils.cpp")
#add_executable(tests ${srcFilesTest})
#target_link_libraries(tests collabclient curl)

