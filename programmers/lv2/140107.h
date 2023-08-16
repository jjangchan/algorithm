//
// Created by jjangchan on 2023/08/14.
// 점 찍기 - 140107
//

#ifndef MAIN_CPP_140107_H
#define MAIN_CPP_140107_H

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    auto cal_y= [&](const long long x) ->long long{
        return (long long)std::floor(std::sqrt(std::pow(d,2)-std::pow(x, 2)));
    };
    for(int x = 0; x <= d; x+= k){
       long long y = cal_y(x);
       answer += (long long)std::floor((y/k))+1;
    }

    return answer;
}

#endif //MAIN_CPP_140107_H
