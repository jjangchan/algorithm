//
// Created by jjangchan on 2021-12-14.
// 문자열 다루기 기본
//

#ifndef MAIN_CPP_12918_H
#define MAIN_CPP_12918_H

#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if(!(s.size() == 4 || s.size() == 6 )) return false;
    bool answer = true;
    for(int i = 0; i < s.size(); i++) if(!(s[i] >= 48 && s[i] <= 57)) return false;
    return answer;
}

#endif //MAIN_CPP_12918_H
