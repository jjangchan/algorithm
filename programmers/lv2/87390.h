//
// Created by jjangchan on 2023/08/28.
// n^2 배열 자르기 - 87390
//

#ifndef MAIN_CPP_87390_H
#define MAIN_CPP_87390_H

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long i = left; i <= right; i++) answer.push_back(std::max(i%n, i/n)+1);
    return answer;
}

#endif //MAIN_CPP_87390_H
