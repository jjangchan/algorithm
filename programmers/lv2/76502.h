//
// Created by jjangchan on 2022/08/22.
// 괄호 회전하기
//

#ifndef MAIN_CPP_76502_H
#define MAIN_CPP_76502_H

#include <stack>
#include <string>
#include <iostream>

bool check(const std::string& s){
    std::stack<char> valid;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '[' || s[i] == '(' || s[i] == '{') valid.push(s[i]);
        else{
            if(valid.empty()) return false;
            char c = valid.top();
            valid.pop();
            int dif = (int)s[i] - (int)c;
            if(!(dif == 1 || dif == 2)) return false;
        }
    }
    return true;
}

int solution(std::string s) {
    if(s.size()&1) return 0;
    int answer = check(s) ? 1 : 0;
    for(int i = 0; i < s.size()-1; i++){
        s = s.substr(1)+s[0];
        answer += check(s) ? 1 : 0;
    }
    return answer;
}

#endif //MAIN_CPP_76502_H
