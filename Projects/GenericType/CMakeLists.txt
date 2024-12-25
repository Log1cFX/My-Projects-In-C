project(GenericType)

include_directories(${GenericType_SOURCE_DIR}/Src)

file(GLOB SOURCES "${GenericType_SOURCE_DIR}/Src/*.c")
add_executable(MyProgram ${SOURCES})
target_include_directories(MyProgram PRIVATE "${GenericType_SOURCE_DIR}/Inc")