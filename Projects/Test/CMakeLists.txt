project(Test)

include_directories(${Linked_list_SOURCE_DIR}/Src)

file(GLOB SOURCES "${Test_SOURCE_DIR}/Src/*.c")
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC "${Test_SOURCE_DIR}/Inc")