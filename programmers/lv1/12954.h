//
// Created by jjangchan on 2021-12-16.
// x 만큼 간격이 있는 n개의 숫자
//

#ifndef MAIN_CPP_12954_H
#define MAIN_CPP_12954_H

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for(int i = 1; i <= n; i++) answer.push_back((long long)x*i);
    return answer;
}

#endif //MAIN_CPP_12954_H
