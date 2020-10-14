cmake_minimum_required(VERSION 3.10)

project(EspRobotControlProj C CXX)

include_directories(src)

add_library(esptestlib src/tryingthis.cpp)

file(GLOB_RECURSE TEST_HEADERS "include/*.hpp" "include/*.h" "include/*.inl")
target_sources(esptestlib PRIVATE ${TEST_HEADERS}) # for intellisense
target_include_directories(esptestlib
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)