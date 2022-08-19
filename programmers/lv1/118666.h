//
// Created by jjangchan on 2022/08/19.
// 성격 유형 검사하기
//

#ifndef MAIN_CPP_118666_H
#define MAIN_CPP_118666_H

#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    std::map<char, int> category;

    for(int i = 0; i < survey.size(); i++){
        int score = choices[i]-4;
        char c = (score > 0) ? survey[i][1] : survey[i][0];
        category[c] += std::abs(score);
    }

    std::string str = "RTCFJMAN";
    for(int i = 0; i < 8; i+= 2){
        (category[str[i]] >= category[str[i+1]]) ? answer += str[i] : answer += str[i+1];
    }
    return answer;
}

#endif //MAIN_CPP_118666_H
