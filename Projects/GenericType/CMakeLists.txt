project(GenericType)

include_directories(${GenericType_SOURCE_DIR}/Src)

file(GLOB SOURCES "${GenericType_SOURCE_DIR}/Src/*.c")
add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC "${GenericType_SOURCE_DIR}/Inc")