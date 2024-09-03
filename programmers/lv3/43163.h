//
// Created by jjangchan on 2024/09/01.
// 43163 - 단어변환
//

#ifndef MAIN_CPP_43163_H
#define MAIN_CPP_43163_H

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0, is = 0, len = words[0].size();
    std::stack<std::pair<std::string, int>> bfs;
    bfs.push({begin, 0});
    while(!bfs.empty()){
        std::pair<std::string, int> p = bfs.top();
        bfs.pop();
        if(p.first == target) {
            is = 1;
            break;
        }
        for(int i = 0; i < words.size(); i++){
            if(!(p.second&(1<<i))){
                int hit = 0;
                for(int j = 0; j < len; j++) if(p.first[j] == words[i][j]) hit++;
                if(hit == len-1) bfs.push({words[i], p.second|(1<<i)});
            }
        }
        answer++;
    }
    return (is) ? answer : 0;
}

#endif //MAIN_CPP_43163_H
