//
// Created by jjangchan on 2021-12-16.
// 정수 내림차순으로 배치하기
//

#ifndef MAIN_CPP_12933_H
#define MAIN_CPP_12933_H
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    std::string s = std::to_string(n);
    std::sort(s.begin(), s.end(), [](char a, char b) -> bool{
        return a > b;
    });
    return std::stol(s);
}

#endif //MAIN_CPP_12933_H
