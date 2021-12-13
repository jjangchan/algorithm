//
// Created by jjangchan on 2021-12-13.
// 수박
//

#ifndef MAIN_CPP_12922_H
#define MAIN_CPP_12922_H
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    for(int i = 0; i < n; i++){
        answer += ((i&1) ? "박" : "수");
    }
    return answer;
}
#endif //MAIN_CPP_12922_H
