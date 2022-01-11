//
// Created by jjangchan on 2022/01/11.
// 튜플
//

#ifndef MAIN_CPP_64065_H
#define MAIN_CPP_64065_H

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map> // -> 배열도 가능
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    std::unordered_map<int, int> m_answer;
    vector<int> answer;
    for(int i = 0; i < s.size(); i++) if(isdigit(s[i])){
        std::string str;
        while(isdigit(s[i])) str.push_back(s[i++]);
        m_answer[stoi(str)]++;
    }
    std::vector<std::pair<int, int>> temp(m_answer.begin(), m_answer.end());
    std::sort(temp.begin(), temp.end(), [](const pair<int,int>& a, const pair<int,int>& b)->bool{
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    });
    for(const auto& i : temp) answer.push_back(i.first);
    return answer;
}

#endif //MAIN_CPP_64065_H
