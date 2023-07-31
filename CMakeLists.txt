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
        example/cuk2.h
        example/bank.h)

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
        programmers/lv2/12953.h programmers/lv2/12951.h
        programmers/lv2/12949.h programmers/lv2/12945.h programmers/lv1/42576.h programmers/lv2/42578.h programmers/lv1/12977.h
        "programmers/lv1/2021kakao_72410" "programmers/lv2/2021kakao_72411.h"
        programmers/lv1/64061.h programmers/lv2/42587.h programmers/lv2/42584.h programmers/lv2/12899.h
        programmers/lv2/1829.h programmers/lv1/77484.h programmers/lv1/81301.h programmers/lv1/67526.h
        programmers/lv1/86051.h programmers/lv1/42748.h programmers/lv1/76501.h programmers/lv1/70128.h programmers/lv1/42840.h
        programmers/lv1/42862.h programmers/lv2/62048.h programmers/lv1/1845.h programmers/lv1/42889.h programmers/lv1/77884.h
        programmers/lv1/68935.h programmers/lv1/12982.h programmers/lv1/68644.h programmers/lv1/12901.h programmers/lv1/86491.h
        programmers/lv1/87389.h programmers/lv1/82612.h programmers/lv1/17681.h programmers/lv1/12903.h programmers/lv1/12922.h
        programmers/lv1/17682.h programmers/lv1/12906.h programmers/lv1/12910.h programmers/lv1/12912.h programmers/lv1/12915.h
        programmers/lv1/12916.h programmers/lv1/12917.h programmers/lv1/12918.h programmers/lv1/12919.h programmers/lv1/12921.h
        programmers/lv1/12925.h programmers/lv1/12926.h programmers/lv1/12928.h programmers/lv1/12930.h programmers/lv1/12969.h
        programmers/lv1/12931.h programmers/lv1/12932.h programmers/lv1/12933.h programmers/lv1/12934.h programmers/lv1/12935.h
        programmers/lv1/12937.h programmers/lv1/12940.h programmers/lv1/12943.h programmers/lv1/12944.h programmers/lv1/12947.h
        programmers/lv1/12948.h programmers/lv1/12950.h programmers/lv1/12954.h programmers/lv2/60057.h programmers/lv2/42888.h
        programmers/lv2/43165.h programmers/lv2/12973.h programmers/lv2/42586.h programmers/lv2/42626.h programmers/lv2/77485.h
        programmers/lv2/1835.h programmers/lv2/60058.h programmers/lv2/17677.h programmers/lv2/81302.h programmers/lv2/67257.h
        programmers/lv2/2021kakao_72412.h programmers/lv2/64065.h programmers/lv2/86052.h programmers/lv2/42577.h programmers/lv2/42746.h
        programmers/lv2/12909.h programmers/lv2/42839.h programmers/lv2/42860.h programmers/lv2/1844.h programmers/lv1/118666.h
        programmers/lv2/70129.h programmers/lv2/12985.h programmers/lv2/76502.h programmers/lv2/17683.h programmers/lv2/1188667.h
        programmers/lv2/42890.h programmers/lv2/12978.h programmers/lv1/178871.h programmers/lv1/161990.h programmers/lv1/133502.h
        programmers/lv1/172928.h programmers/lv1/kakao_150370.h programmers/lv1/160586.h programmers/lv2/181188.h programmers/lv2/181187.h
        programmers/lv2/1778870.h programmers/lv2/176962.h programmers/lv2/172927.h programmers/lv2/169199.h programmers/lv2/169198.h
        programmers/lv2/160585.h programmers/lv2/159993.h)

set(DataStructure
        datastructure/binarySearch.h
        datastructure/MyBinarySearchTree.h
        datastructure/MyHeep.h
        datastructure/MyLinkedList.h
        datastructure/MyQueue.h
        datastructure/MySort.h
        datastructure/MyHashMap.h
        datastructure/MyVector.h datastructure/MySet.h )

add_executable(${PROJECT_NAME} main.cpp ${SRC} ${BAEKJOON} ${PROGRAMMERS} ${DataStructure})