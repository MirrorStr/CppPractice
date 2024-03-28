cmake_minimum_required(VERSION 3.10)

project(C++)

add_subdirectory(src)

add_executable(main main.cc)

target_link_libraries(main PUBLIC src)

# string(TIMESTAMP COMPILE_TIME "%Y-%m-%d %H:%M:%S" UTC) # 打印时间，但是好像有点问题

message(${COMPILE_TIME})

# add_custom_target(measure_compile_time ALL
#   COMMAND ${CMAKE_COMMAND} --build .
#   COMMAND ${CMAKE_COMMAND} -E echo "Compile took: $<TARGET_PROPERTY:compile_time,TIME>"
#   )

target_include_directories(main PUBLIC ${PROJECT_SOURCE_DIR}/include)