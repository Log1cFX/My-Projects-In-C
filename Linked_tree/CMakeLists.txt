project(Linked_tree)

include_directories(${Linked_tree_SOURCE_DIR}/Src)

file(GLOB SOURCES "${Linked_tree_SOURCE_DIR}/Src/*.c")
add_executable(MyProgram ${SOURCES})
target_include_directories(MyProgram PRIVATE "${Linked_tree_SOURCE_DIR}/Inc")