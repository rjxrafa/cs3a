cmake_minimum_required(VERSION 3.13)
project(cs3a)

set (CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES *.cpp
                  fraction_quiz/*.cpp)

file(GLOB INCLUDE fraction_quiz/*.h)

if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++)
endif()

add_executable(cs3a ${SOURCES} ${INCLUDE})