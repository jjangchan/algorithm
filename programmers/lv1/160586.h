//
// Created by jjangchan on 2023/07/10.
// 대충 만든 자판
//

#ifndef MAIN_CPP_160586_H
#define MAIN_CPP_160586_H

#include <string>
#include <vector>
#include <iostream>

#define MAX 101

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    std::vector<int> key_map(26, MAX);
    for(const auto& key :keymap) for(int i = 0; i < key.size(); i++){
        key_map[key[i]-'A'] = min(i+1, key_map[key[i]-'A']);
    }
    for(const auto& str : targets){
        int num = 0;
        for(const char c : str){
            if(key_map[c-'A'] == MAX){
                num = -1;
                break;
            }else num += key_map[c-'A'];
        }
        answer.push_back(num);
    }
    return answer;
}

#endif //MAIN_CPP_160586_H
