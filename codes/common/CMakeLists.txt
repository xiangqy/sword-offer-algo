cmake_minimum_required(VERSION 3.27)
project(common)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
include_directories(./log/include/)

aux_source_directory(../common/log LOG_SRCS)
add_library(${PROJECT_NAME} ${LOG_SRCS})