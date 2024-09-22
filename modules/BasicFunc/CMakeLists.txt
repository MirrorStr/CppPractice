set(MODULE_NAME BasicFuncLib)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)

add_library(${MODULE_NAME} ${SRC_LIST})