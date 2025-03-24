###############################################################################
# 项目设置 #
cmake_minimum_required(VERSION 3.10)

project(Cpp-Parctice
    VERSION 1.0
    DESCRIPTION "用于在电脑上练习C++"
)    # 设置项目名称

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")     # 设置可执行文件输出目录
# 设置 vcpkg 的工具链文件
set(CMAKE_TOOLCHAIN_FILE "/home/wanjuncong/PARA/resource/vcpkg-master/scripts/buildsystems/vcpkg.cmake")

###############################################################################
# main程序设置 #

# 查找fmt库
find_package(fmt REQUIRED)
find_package(jsoncpp REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_executable(main main.cc)

# 链接库
target_link_libraries(main PUBLIC 
    BasicFuncLib
    lib::WhiteBorad  # 测试用的模块
)  

# 链接三方库
target_link_libraries(main PRIVATE 
    fmt::fmt
    JsonCpp::JsonCpp
    spdlog::spdlog
)

# 使用动态库 继续添加json库
target_include_directories(main PUBLIC 
    ${PROJECT_SOURCE_DIR}/modules/BasicFunc
    ${PROJECT_SOURCE_DIR}/modules/WhiteBorad
    ${PROJECT_SOURCE_DIR}/include
)
###############################################################################
# 添加其他组件 #
add_subdirectory(modules)

###############################################################################
# EOF #