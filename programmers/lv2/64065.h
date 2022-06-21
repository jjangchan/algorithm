//
// Created by jjangchan on 2022/01/11.
// 튜플
//

#ifndef MAIN_CPP_64065_H
#define MAIN_CPP_64065_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    int counts[100001] = {0,};
    vector<int> answer;
    for(int i = 0; i < s.size(); i++) if(isdigit(s[i])){
        std::string str;
        while(isdigit(s[i])) str.push_back(s[i++]);
        counts[stoi(str)]++;
    }
    std::vector<std::pair<int, int>> temp;
    for(int i = 1; i <= 100000; i++) if(counts[i]) temp.push_back(make_pair(i, counts[i]));
    std::sort(temp.begin(), temp.end(), [](const pair<int,int>& a, const pair<int,int>& b)->bool{
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    });
    for(const auto& i : temp) answer.push_back(i.first);
    return answer;
}

#endif //MAIN_CPP_64065_H
