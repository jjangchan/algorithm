//
// Created by JKC on 14/05/2020.
//
#include <iostream>
#include <chrono>
#include <functional>
#ifndef ALGORITHM_2_1_2_H
#define ALGORITHM_2_1_2_H

int test()
{
    auto start_clock = std::chrono::steady_clock::now();
    int num;
    std::cin >> num;
    for(int i=1; i<=num;i++)
    {
        for(int j=1; j<=i;j++)
        {
            std::cout << "*" ;
        }
        std::cout << "" << std::endl;
    }
    auto end_clock = std::chrono::steady_clock::now();
    unsigned long elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_clock - start_clock).count();
    std::cout << elapsed_time;
    return 0;
}

void funtions(int num)
{
    if(num == 0)return;
    std::cout << "*" ;
    funtions(num-1);
}

int test2()
{
    auto start_clock = std::chrono::steady_clock::now();
    int num;
    std::cin >> num;
    for(int i=1; i<=num;i++)
    {
        funtions(i);
        std::cout << "" << std::endl;
    }
    auto end_clock = std::chrono::steady_clock::now();
    unsigned long elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_clock - start_clock).count();
    std::cout << elapsed_time;
    return 0;
}

#endif //ALGORITHM_2_1_2_H
