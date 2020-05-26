//
// Created by JKC on 14/05/2020.
//
#include <iostream>
#include <vector>
#ifndef ALGORITHM_2020_05_14_2_1_4_H
#define ALGORITHM_2020_05_14_2_1_4_H

int go()
{
    int max_list[8]={0,};

    int max_num;

    std::cin >> max_list[0];
    for(int i=1; i< 9; i++)
    {
        std::cin >> max_list[i];
        if(max_list[i-1] < max_list[i])
        {
            max_num = i;
        }
        else
        {
            max_num = i-1;
        }
    }

    std::cout << max_num+1 << std::endl << max_list[max_num];

    return 0;
}

#endif //ALGORITHM_2020_05_14_2_1_4_H
