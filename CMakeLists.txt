cmake_minimum_required(VERSION 3.13)
project(cs3a)

set (CMAKE_CXX_STANDARD 11)

include_directories(Stack)

set (SOURCES main.cpp)

set (INCLUDE Stack/stack.h
             Stack/driver.h)

if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++)
endif()

add_executable(cs3a ${SOURCES}
                    ${INCLUDE})