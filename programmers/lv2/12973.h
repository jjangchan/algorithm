//
// Created by jjangchan on 2021-12-21.
// 짝지어 제거하기
//

#ifndef MAIN_CPP_12973_H
#define MAIN_CPP_12973_H

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    std::stack<char> chars;
    chars.push(s[0]);
    for(int i = 1; i < s.size(); i++){
        if(!chars.empty() && chars.top() == s[i]){
            while(!chars.empty()){
                if(chars.top() == s[i]){
                    chars.pop();
                    i++;
                }else break;
            }
        }else chars.push(s[i]);
    }
    return chars.empty() ? 1 : 0;
}

#endif //MAIN_CPP_12973_H
