cmake_minimum_required(VERSION 3.10)

project(C++)    # 设置项目名称

add_subdirectory(src)   # 添加子目录

add_executable(main main.cc)

target_link_libraries(main PUBLIC src)  # 链接库

string(TIMESTAMP COMPILE_TIME "%Y-%m-%d %H:%M:%S" UTC) # 打印当前时间

message(${COMPILE_TIME})

target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/include)