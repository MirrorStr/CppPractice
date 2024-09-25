set(MODULE_NAME WhiteBorad)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)

add_library(${MODULE_NAME} ${SRC_LIST})
add_library(lib::${MODULE_NAME} ALIAS ${MODULE_NAME}) #取别名