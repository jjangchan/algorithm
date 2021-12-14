//
// Created by jjangchan on 2021-12-14.
// 나누어 떨어지는 숫자 배열
//

#ifndef MAIN_CPP_12910_H
#define MAIN_CPP_12910_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    std::sort(arr.begin(), arr.end());
    for(int& i : arr) if(!(i%divisor)) answer.push_back(i);
    if(answer.size() == 0) answer.push_back(-1);
    return answer;
}

#endif //MAIN_CPP_12910_H
