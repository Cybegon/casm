file(GLOB_RECURSE PHSRC ${CMAKE_SOURCE_DIR}/src/public/*.h)
file(GLOB_RECURSE HSRC ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

include_directories(${CMAKE_SOURCE_DIR}/src/public)
include_directories(${CMAKE_SOURCE_DIR}/src/public/casm)

add_executable(casm ${SRC} ${PHSRC} ${HSRC})
target_link_libraries(casm sl)
