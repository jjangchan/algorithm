//
// Created by jjangchan on 2021-11-17.
// 76501 - 음양 더하기
//

#ifndef MAIN_CPP_76501_H
#define MAIN_CPP_76501_H

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for(int i = 0; i < absolutes.size(); i++) answer += ((signs[i]) ? absolutes[i] : absolutes[i]*-1);
    return answer;
}

#endif //MAIN_CPP_76501_H
