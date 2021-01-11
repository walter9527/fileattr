cmake_minimum_required(VERSION 3.16.3)
project(fileattr C)

set(CMAKE_C_STANDARD 99)

# 源文件目录
aux_source_directory(common DIR_COMMON)

## 头文件目录
include_directories(include)

set(HOME "/home/zhangliao")

# debug模式，可以调试
SET(CMAKE_BUILD_TYPE DEBUG)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

#SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${HOME})
SET(EXECUTABLE_OUTPUT_PATH ${HOME})

#set_target_properties(${PROJECT_NAME}
#    PROPERTIES
##    ARCHIVE_OUTPUT_DIRECTORY "/home/xy/cmake_practice/lib/"
##    LIBRARY_OUTPUT_DIRECTORY "/home/xy/cmake_practice/lib/"
#    RUNTIME_OUTPUT_DIRECTORY "/home/zhangliao/"
#)

add_executable(fileattr fileattr/lesson01.c ${DIR_COMMON})

