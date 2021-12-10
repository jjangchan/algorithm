//
// Created by jjangchan on 2021-11-17.
// 70128 - 내적
//

#ifndef MAIN_CPP_70128_H
#define MAIN_CPP_70128_H

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    for(int i = 0; i < a.size(); i++) answer += (a[i]*b[i]);
    return answer;
}

#endif //MAIN_CPP_70128_H
