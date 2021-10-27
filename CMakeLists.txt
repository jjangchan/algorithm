cmake_minimum_required(VERSION 3.15)
project(algorithm)

set(CMAKE_CXX_STANDARD 17)
if (WIN32)
    set(CMAKE_CXX_FLAGS "-fexec-charset=CP949")
endif()

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
        programmers/1829.h
        baekjoon/1753.h
        "programmers/Ex1)2021KakaoBlind.h"
        "programmers/Ex2)2021KakaoBlind.h"
        "programmers/Ex3)2021KakaoBlind.h"
        baekjoon/1786.h
        "programmers/Ex3)2021KakaoBlind2.h"
        "programmers/Ex1)2021KakaoBlind2.h"
        "programmers/Ex2)2021KakaoBlind2.h"
        baekjoon/2667.h
        programmers/12953.h
        programmers/12951.h
        programmers/12949.h
        programmers/12945.h
        programmers/42576.h
        programmers/42578.h
        programmers/12977.h
        baekjoon/1325.h
        baekjoon/2150.h)

add_executable(${PROJECT_NAME} main.cpp ${SRC})