//
// Created by jjangchan on 2022/08/16.
// 가장큰수
//

#ifndef MAIN_CPP_42746_H
#define MAIN_CPP_42746_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    std::string answer;
    std::sort(numbers.begin(), numbers.end(), [](const int a, const int b)->bool{
        std::string s_a = std::to_string(a);
        std::string s_b = std::to_string(b);
        return s_a+s_b > s_b+s_a;
    });
    for(auto i : numbers) answer.append(std::to_string(i));
    return (0 == answer[0]-'0') ? "0" : answer;
}

#endif //MAIN_CPP_42746_H
