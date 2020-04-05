cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
project(TechProgGame LANGUAGES CXX)

add_compile_options(-Wall -std=c++1z)

include_directories(include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TechProgGame_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${TechProgGame_SOURCE_DIR}/lib)
add_subdirectory(src)
add_executable(Game main.cpp)

target_link_libraries(Game archer)
target_link_libraries(Game cavalry)
target_link_libraries(Game cavalry_archer)
target_link_libraries(Game cavalry_lancer)
target_link_libraries(Game field)
target_link_libraries(Game lancer)
target_link_libraries(Game warriors)

