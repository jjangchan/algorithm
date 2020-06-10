cmake_minimum_required(VERSION 3.15)
project(algorithm)

set(CMAKE_CXX_STANDARD 17)

set(SRC
        example/2.1.2.h
        example/2020.05.14_2.1.3.h
        example/2020.05.14_2.1.4.h
        example/2020.05.14_2.1.5.h
        programmers/64061.h
        programmers/42587.h
        programmers/42584.h
        programmers/12899.h
        programmers/12899_2.h
        programmers/1829.h)

add_executable(${PROJECT_NAME} main.cpp ${SRC})