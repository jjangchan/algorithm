//
// Created by jjangchan on 2021-12-10.
// 예산
//

#ifndef MAIN_CPP_12982_H
#define MAIN_CPP_12982_H
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    std::sort(d.begin(), d.end());
    int sum = 0;
    for(int& krw : d){
        sum += krw;
        if(sum > budget) break;
        answer++;
    }
    return answer;
}

#endif //MAIN_CPP_12982_H
