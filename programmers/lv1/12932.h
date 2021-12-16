//
// Created by jjangchan on 2021-12-16.
// 자연수 뒤집어 배열로 만들기
//

#ifndef MAIN_CPP_12932_H
#define MAIN_CPP_12932_H

#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    std::string s = std::to_string(n);
    for(int i = s.size()-1; i >= 0; i--) answer.push_back(std::stoi(s.substr(i, 1)));
    return answer;
}

#endif //MAIN_CPP_12932_H
