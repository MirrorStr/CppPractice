cmake_minimum_required(VERSION 3.10)

project(C++)    # 设置项目名称

add_subdirectory(src)   # 添加子目录

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")     # 设置可执行文件输出目录

# 头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include/jsoncpp)

link_directories(${PROJECT_SOURCE_DIR}/lib/jsoncpp)

add_executable(main main.cc)

target_link_libraries(main PUBLIC src jsoncpp)  # 链接库

target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/include)

