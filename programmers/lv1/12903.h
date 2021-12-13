//
// Created by jjangchan on 2021-12-13.
// 가운데 글자 가져오기
//

#ifndef MAIN_CPP_12903_H
#define MAIN_CPP_12903_H

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int c = s.size()/2;
    return (s.size()%2) ? s.substr(c, 1) : s.substr(c-1,2);
}

#endif //MAIN_CPP_12903_H
