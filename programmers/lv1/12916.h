//
// Created by jjangchan on 2021-12-14.
// 문자열 내 p와 y의 개수
//

#ifndef MAIN_CPP_12916_H
#define MAIN_CPP_12916_H

#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int p = 0, y = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'p' || s[i] == 'P') p++;
        else if(s[i] == 'y' || s[i] == 'Y') y++;
    }
    return p==y;
}

#endif //MAIN_CPP_12916_H
