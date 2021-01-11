cmake_minimum_required(VERSION 3.5)

project(qm)

set(CMAKE_CXX_COMPILER clang++)

add_compile_options(-std=c++17 -stdlib=libc++ -Wall -Werror -O2 -g)

file(GLOB_RECURSE src src/qm/*.cpp)

add_executable(qm ${src} src/main.cpp)
target_include_directories(qm PUBLIC src/)
target_link_libraries(qm /usr/local/lib/liblgpp.a)
target_include_directories(qm PUBLIC /usr/local/include/)

install(FILES build/qm DESTINATION bin)
