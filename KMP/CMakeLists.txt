cmake_minimum_required(VERSION 3.15)

project(KMP)

set(CXX_SOURCE test.cpp KMP-algo.cpp)

add_library(LPS LPS.cpp)

foreach(CXX_FILE ${CXX_SOURCE})
    get_filename_component(TARGET_NAME ${CXX_FILE} NAME_WE)
    add_executable(${TARGET_NAME} ${CXX_FILE})
    target_link_libraries(${TARGET_NAME} PRIVATE LPS)
endforeach()

message(STATUS "Finish configuration.")

