//
// Created by jjangchan on 2021-12-14.
// 문자열 내림차순으로 배치하기
//

#ifndef MAIN_CPP_12917_H
#define MAIN_CPP_12917_H
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    std::sort(s.begin(), s.end(), [](char a, char b)->bool{
        return a > b;
    });
    return s;
}
#endif //MAIN_CPP_12917_H
