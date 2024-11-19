# cmake version
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
########################################################################################################################
# Project Settings                                                                                                     #
########################################################################################################################
set(project_name "she_test")
PROJECT(${project_name}
        VERSION 0.0.1
        LANGUAGES CXX)

option(build_release "build release" OFF)
option(build_tests "build with test target" ON)
option(build_shared_libs "enable shared libs" OFF)

# Pre setting of target-src
file(GLOB_RECURSE src "${CMAKE_SOURCE_DIR}/src/*")
set(src_link_dependency)

# Pre setting of target-test
if (build_tests STREQUAL ON)
    set(test_name "${project_name}_test")
    set(test_link_dependency)
endif ()

########################################################################################################################
# include                                                                                                              #
########################################################################################################################
include(${CMAKE_SOURCE_DIR}/cmake/build.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/import_third_party.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/target_src.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/target_test.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/install.cmake)
