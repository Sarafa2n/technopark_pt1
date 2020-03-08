cmake_minimum_required(VERSION 3.15)
project(DZ1)

add_executable(${PROJECT_NAME} src/main.c)

add_subdirectory(src/lib)
target_link_libraries(DZ1 utils)

add_executable(Test unit_test.c)
target_link_libraries(Test utils)

enable_testing()

add_test(UnitTest Test)
