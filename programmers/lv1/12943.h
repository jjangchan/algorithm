//
// Created by jjangchan on 2021-12-16.
// 콜라츠 추측
//

#ifndef MAIN_CPP_12943_H
#define MAIN_CPP_12943_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {
    int answer = 0;
    long n = num;
    while(n != 1 && answer++ <= 500) n = n&1 ? n*3+1 : n/2;

    return answer > 500 ? -1 : answer;
}

#endif //MAIN_CPP_12943_H
