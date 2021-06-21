cmake_minimum_required(VERSION 3.13.4 FATAL_ERROR)

project(abc)

if(WIN32)
    add_compile_definitions(__WINDOWS__)
elseif(APPLE)
    add_compile_definitions(__MACOS__)
elseif(LINUX)
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


target_compile_features(abc PRIVATE cxx_std_17)
