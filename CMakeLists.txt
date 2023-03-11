cmake_minimum_required(VERSION 3.10)

project(spidev library)
set(CMAKE_CXX_FLAGS "-g -Wall")

include_directories(src/)

add_library(spidev-lib src/spidev.cpp)
add_executable(spidev-test sample/spidev-test.cpp)
target_link_libraries(spidev-test spidev-lib)
add_dependencies(spidev-test spidev-lib++)

INSTALL(TARGETS  spidev-lib
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
INSTALL( FILES src/spidev_lib++.h DESTINATION include)

