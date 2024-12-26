project(Linkedlist)

include_directories(${Linked_list_SOURCE_DIR}/Src)

file(GLOB SOURCES "${Linkedlist_SOURCE_DIR}/Src/*.c")
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC "${Linkedlist_SOURCE_DIR}/Inc")
target_link_libraries(${PROJECT_NAME} GenericType)