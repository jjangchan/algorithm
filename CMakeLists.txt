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
        example/bank.h example/2023.12.17.h example/2023.12.18.h example/2023.12.20.h example/2023.12.21.h example/2023.12.22.h example/2023.12.23.h example/2023.12.24.h)

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
        programmers/lv2/160585.h programmers/lv2/159993.h programmers/lv2/155651.h programmers/lv2/154540.h programmers/lv2/154539.h
        programmers/lv2/154538.h programmers/lv2/152996.h programmers/lv2/150369.h programmers/lv2/150368.h programmers/lv2/148653.h
        programmers/lv2/148652.h programmers/lv2/147354.h programmers/lv2/142085.h programmers/lv2/140107.h programmers/lv2/138476.h
        programmers/lv2/135807.h programmers/lv2/134239.h programmers/lv2/132265.h programmers/lv2/131704.h programmers/lv2/131701.h
        programmers/lv2/131130.h programmers/lv2/131127.h programmers/lv2/92342.h programmers/lv2/92341.h programmers/lv2/92335.h
        programmers/lv2/87946.h programmers/lv2/87390.h programmers/lv2/86971.h programmers/lv1/250137.h programmers/lv1/250125.h
        programmers/lv1/250121.h programmers/lv2/250136.h programmers/lv2/250135.h programmers/lv2/87377.h programmers/lv1/258712.h
        programmers/lv2/258711.h programmers/lv2/84512.h programmers/lv2/77885.h programmers/lv2/68936.h programmers/lv2/68645.h
        programmers/lv2/49994.h programmers/lv2/49993.h programmers/lv2/42885.h programmers/lv2/42883.h programmers/lv2/17680.h programmers/lv2/17687.h)

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