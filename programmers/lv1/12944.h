//
// Created by jjangchan on 2021-12-16.
// 평균 구하기
//

#ifndef MAIN_CPP_12944_H
#define MAIN_CPP_12944_H

#include <string>
#include <vector>
#include <numeric>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    return   (double)std::accumulate(arr.begin(), arr.end(), 0,
                                     [&arr](const int& a, const int& b)->int{return (a+b);})/(double)arr.size();;
}

#endif //MAIN_CPP_12944_H
