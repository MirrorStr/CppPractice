###############################################################################
set(OBJ_NAME dbus-server)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)

find_package(DBus1 REQUIRED)

add_executable(${OBJ_NAME} ${SRC_LIST})

target_link_libraries(${OBJ_NAME} PRIVATE  
    ${DBus1_LIBRARIES}
)  

###############################################################################
# EOF #