cmake_minimum_required(VERSION 2.8.2 FATAL_ERROR)
project(collab-poc)

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message(FATAL_ERROR "in-source build not allowed. Use another directory.")
endif()


# ------------------------------------------------------------------------------
# Various / Dependencies
# ------------------------------------------------------------------------------
set(collab_dependency_dir "${CMAKE_SOURCE_DIR}/dependencies/")
set(collab_gitmodule_dir "${CMAKE_SOURCE_DIR}/gitmodules/")

include("CMake/AddCompilerFlags.cmake")

include("CMake/ExternalProjects/Collabclient.cmake")
include("CMake/ExternalProjects/Collabdata.cmake")


# ------------------------------------------------------------------------------
# GraphEditor
# ------------------------------------------------------------------------------
option(collab_graphiceditor "Build GraphicEditor client" ON)
if(collab_graphiceditor)
    message(STATUS "Build GraphicEditor client")
    include("CMake/AddGraphiceditor.cmake")
endif()

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



# ------------------------------------------------------------------------------
# Mvk
# ------------------------------------------------------------------------------
option(collab_mvk "Build Mvk database client" ON)
if(collab_mvk)
    message(STATUS "Build Mvk db client")
    include("CMake/AddMvk.cmake")
endif()

