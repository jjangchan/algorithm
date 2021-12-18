//
// Created by jjangchan on 2021-12-13.
//

#ifndef MAIN_CPP_82612_H
#define MAIN_CPP_82612_H
#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    // 등차수열
    long long result = ((long long)count*(long long)(price+price*count))/(long long)2;
    std::cout << result;
    return result > money ? result-money : 0;
}
#endif //MAIN_CPP_82612_H
