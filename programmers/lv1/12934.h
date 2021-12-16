//
// Created by jjangchan on 2021-12-16.
// 정수 제곱근 판별
//

#ifndef MAIN_CPP_12934_H
#define MAIN_CPP_12934_H

#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = sqrtl(n);
    return powl(answer, 2) == n ? powl(answer+1, 2) : -1;
}

#endif //MAIN_CPP_12934_H
