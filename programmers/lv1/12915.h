//
// Created by jjangchan on 2021-12-14.
// 문자열 내 마음대로 정렬하기
//

#ifndef MAIN_CPP_12915_H
#define MAIN_CPP_12915_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    std::sort(strings.begin(), strings.end(),
              [n](std::string a, std::string b) -> bool{
                  return a[n] == b[n] ? a < b : a[n] < b[n];});
    return strings;
}


#endif //MAIN_CPP_12915_H
