//
// Created by jjangchan on 2022/08/16.
// 올바른 괄호
//

#ifndef MAIN_CPP_12909_H
#define MAIN_CPP_12909_H
#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int count = 0;
    for(const auto& c : s){ // N
        if(count < 0) return false;
        else if(c == '(') count++;
        else count--;
    }
    return count == 0;
}

#endif //MAIN_CPP_12909_H
