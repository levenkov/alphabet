cmake_minimum_required(VERSION 3.13.4 FATAL_ERROR)

project(abc)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

conan_basic_setup()

find_package(Boost COMPONENTS range filesystem REQUIRED)
find_package(Threads REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(abc ${SOURCES})

target_link_libraries(abc PRIVATE Boost::filesystem Threads::Threads)
target_include_directories(abc BEFORE PRIVATE ${CMAKE_SOURCE_DIR}/src)


target_compile_features(abc PRIVATE cxx_std_17)
