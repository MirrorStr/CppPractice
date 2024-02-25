cmake_minimum_required(VERSION 3.10)

project(C++)

add_executable(main main.cc)

string(TIMESTAMP COMPILE_TIME "%Y-%m-%d %H:%M:%S" UTC)

message(${COMPILE_TIME})

# add_custom_target(measure_compile_time ALL
#   COMMAND ${CMAKE_COMMAND} --build .
#   COMMAND ${CMAKE_COMMAND} -E echo "Compile took: $<TARGET_PROPERTY:compile_time,TIME>"
#   )