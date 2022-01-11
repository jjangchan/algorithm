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
        baekjoon/2618.h baekjoon/2757.h )

set(PROGRAMMERS
        programmers/12953.h programmers/12951.h
        programmers/12949.h programmers/12945.h programmers/lv1/42576.h programmers/42578.h programmers/lv1/12977.h
        "programmers/lv1/2021kakao_72410" "programmers/lv2/2021kakao_72411.h"
        programmers/lv1/64061.h programmers/42587.h programmers/42584.h programmers/12899.h
        programmers/12899_2.h programmers/lv2/1829.h programmers/lv1/77484.h programmers/lv1/81301.h programmers/lv1/67526.h
        programmers/lv1/86051.h programmers/lv1/42748.h programmers/lv1/76501.h programmers/lv1/70128.h programmers/lv1/42840.h
        programmers/lv1/42862.h programmers/62048.h programmers/lv1/1845.h programmers/42889.h programmers/lv1/77884.h
        programmers/lv1/68935.h programmers/lv1/12982.h programmers/lv1/68644.h programmers/lv1/12901.h programmers/lv1/86491.h
        programmers/lv1/87389.h programmers/lv1/82612.h programmers/lv1/17681.h programmers/lv1/12903.h programmers/lv1/12922.h
        programmers/lv1/17682.h programmers/lv1/12906.h programmers/lv1/12910.h programmers/lv1/12912.h programmers/lv1/12915.h
        programmers/lv1/12916.h programmers/lv1/12917.h programmers/lv1/12918.h programmers/lv1/12919.h programmers/lv1/12921.h
        programmers/lv1/12925.h programmers/lv1/12926.h programmers/lv1/12928.h programmers/lv1/12930.h programmers/lv1/12969.h
        programmers/lv1/12931.h programmers/lv1/12932.h programmers/lv1/12933.h programmers/lv1/12934.h programmers/lv1/12935.h
        programmers/lv1/12937.h programmers/lv1/12940.h programmers/lv1/12943.h programmers/lv1/12944.h programmers/lv1/12947.h
        programmers/lv1/12948.h programmers/lv1/12950.h programmers/lv1/12954.h programmers/lv2/60057.h programmers/lv2/42888.h
        programmers/lv2/43165.h programmers/lv2/12973.h programmers/lv2/42586.h programmers/lv2/42626.h programmers/lv2/77485.h
        programmers/lv2/1835.h programmers/lv2/60058.h programmers/lv2/17677.h programmers/lv2/81302.h programmers/lv2/67257.h programmers/lv2/2021kakao_72412.h programmers/lv2/64065.h)

add_executable(${PROJECT_NAME} main.cpp ${SRC} ${BAEKJOON} ${PROGRAMMERS})