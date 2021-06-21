cmake_minimum_required(VERSION 3.13.4 FATAL_ERROR)

project(abc)

if(${CMAKE_SYSTEM_NAME} STREQUAL Windows OR ${CMAKE_SYSTEM_NAME} STREQUAL MSYS)
    add_compile_definitions(__WINDOWS__)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL Darwin)
    add_compile_definitions(__MACOS__)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL Linux)
    add_compile_definitions(__LINUX__)
else()
    message(FATAL_ERROR "Unexpected OS")
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

conan_basic_setup()

find_package(Boost COMPONENTS filesystem REQUIRED)
find_package(Threads REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(abc ${SOURCES})

target_link_libraries(abc PRIVATE Boost::filesystem Threads::Threads)
target_include_directories(abc BEFORE PRIVATE ${CMAKE_SOURCE_DIR}/src)


target_compile_features(abc PRIVATE cxx_std_14)
