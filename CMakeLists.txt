cmake_minimum_required(VERSION 3.10)

project(C++)    # 设置项目名称

add_subdirectory(src)   # 添加子目录

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")     # 设置可执行文件输出目录

# 头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include/jsoncpp)

# 使用动态库 查找json库
find_library(JSONCPP_LIBRARY
             NAMES jsoncpp
             HINTS ${PROJECT_SOURCE_DIR}/lib/jsoncpp)

add_executable(main main.cc)

target_link_libraries(main PUBLIC src)  # 链接库

# 使用动态库 继续添加json库
target_link_libraries(main PRIVATE ${JSONCPP_LIBRARY})

target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/include)

