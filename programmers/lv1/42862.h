//
// Created by jjangchan on 2021-12-06.
// 42862 - 체육복
//

#ifndef ALGORITHM_42862_H
#define ALGORITHM_42862_H

#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    std::sort(lost.begin(), lost.end());
    std::sort(reserve.begin(), reserve.end());
    // 차집합 (lost-reserve , reserve-lost)
    int size = lost.size()+reserve.size();
    std::vector<int> difference_lost(size);
    std::vector<int> difference_reserve(size);
    std::vector<int>::iterator iter;
    iter = set_difference(lost.begin(), lost.end(), reserve.begin(), reserve.end(), difference_lost.begin());
    difference_lost.resize(iter-difference_lost.begin()); // 공간 제거
    iter = set_difference(reserve.begin(), reserve.end(), lost.begin(), lost.end(), difference_reserve.begin());
    difference_reserve.resize(iter-difference_reserve.begin()); // 공간 제거
    int count = 0;

    // 제거 우선순위 : 1. 중복값 2. 왼쪽 3. 오른쪽
    for(int i = 0; i < difference_reserve.size(); i++){
        int value = difference_reserve[i];
        auto down = std::find(difference_lost.begin(), difference_lost.end(), value-1);
        auto up = std::find(difference_lost.begin(), difference_lost.end(), value+1);
        if(down != difference_lost.end()) difference_lost.erase(down);
        else if(up != difference_lost.end()) difference_lost.erase(up);
    }

    return n-difference_lost.size();
}

#endif //MAIN_CPP_42862_H
