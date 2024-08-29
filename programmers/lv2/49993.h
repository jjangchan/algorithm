//
// Created by jjangchan on 2024/07/21.
// 49993 - 스킬트리
//

#ifndef MAIN_CPP_49993_H
#define MAIN_CPP_49993_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int pre_skill[26];

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(char c : skill) pre_skill[c-'A'] = 1;
    for(const std::string& str : skill_trees){
        int index = 0, is = 1;
        for(char c : str){
            if(pre_skill[c-'A']){
                if(skill[index] == c) index++;
                else {
                    is = 0;
                    break;
                }
            }
        }
        if(is) answer++;
    }
    return answer;
}

#endif //MAIN_CPP_49993_H
