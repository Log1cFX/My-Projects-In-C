project(Linkedlist)

include_directories(${Linked_list_SOURCE_DIR}/Src)

file(GLOB SOURCES "${Linkedlist_SOURCE_DIR}/Src/*.c")
add_executable(MyProgram ${SOURCES})
target_include_directories(MyProgram PRIVATE "${Linkedlist_SOURCE_DIR}/Inc")