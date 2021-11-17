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
        example/2020.05.14_2.1.5.h)


set(PROGRAMMERS
        programmers/12953.h
        programmers/12951.h
        programmers/12949.h
        programmers/12945.h
        programmers/42576.h
        programmers/42578.h
        programmers/12977.h
        "programmers/Ex3)2021KakaoBlind2.h"
        "programmers/Ex1)2021KakaoBlind2.h"
        "programmers/Ex2)2021KakaoBlind2.h"
        "programmers/Ex1)2021KakaoBlind.h"
        "programmers/Ex2)2021KakaoBlind.h"
        "programmers/Ex3)2021KakaoBlind.h"
        programmers/64061.h
        programmers/42587.h
        programmers/42584.h
        programmers/12899.h
        programmers/12899_2.h
        programmers/1829.h
        programmers/77484.h
        programmers/81301.h
        programmers/67526.h
        programmers/86051.h
        programmers/42748.h
        programmers/76501.h
        programmers/70128.h programmers/42840.h)

set(BAEKJOON
        baekjoon/1753.h
        baekjoon/1786.h
        baekjoon/2667.h
        baekjoon/1325.h
        baekjoon/2150.h
        baekjoon/4196.h
        baekjoon/11055.h
        baekjoon/11053.h
        baekjoon/2231.h
        baekjoon/4344.h
        baekjoon/2667.h
        baekjoon/2618.h programmers/42840.h)

add_executable(${PROJECT_NAME} main.cpp ${SRC} ${BAEKJOON} ${PROGRAMMERS})