cmake_minimum_required(VERSION 3.13)
project(cs3a)

set (CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES *.cpp
                  fraction_quiz/*.cpp
                  copy/*.cpp
#                  polynomial/*.cpp
                  smart_array/*.cpp)

file(GLOB INCLUDE fraction_quiz/*.h
                  copy/*.h
#                  polynomial/*.h
                  smart_array/*.h)

if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++)
endif()

add_executable(cs3a ${SOURCES} ${INCLUDE} statistics/driver.h statistics/statistics.h number_generator/phone_number_generator.h function_pointers/fptr.cpp 2d_array/dynamic_array.cpp 2d_array/modify_array.cpp)