//
// Created by jjangchan on 2021-10-08.
// 42578 - 위장
//

#ifndef ALGORITHM_42578_H
#define ALGORITHM_42578_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    std::unordered_map<std::string, int> m;
    for(int i = 0; i < clothes.size(); i++) m[clothes[i][1]]++;  
    for(auto iter = m.begin(); iter != m.end(); ++iter) answer *= (iter->second+1);
    return answer-1;
}


#endif //ALGORITHM_42578_H
