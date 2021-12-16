//
// Created by jjangchan on 2021-12-16.
// 짝수와 홀수
//

#ifndef MAIN_CPP_12937_H
#define MAIN_CPP_12937_H

#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    return num&1 ? "Odd" : "Even";
}

#endif //MAIN_CPP_12937_H
