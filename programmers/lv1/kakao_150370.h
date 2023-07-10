//
// Created by jjangchan on 2023/07/07.
// kakao - 개인정보 수집 유효기간
//

#ifndef MAIN_CPP_KAKAO_150370_H
#define MAIN_CPP_KAKAO_150370_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

std::map<char, int> mm_category;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int day = (std::stoi(today.substr(0,4))*28*12) + ((std::stoi(today.substr(5,2))-1)*28) + std::stoi(today.substr(8));
    for(std::string& str : terms){
        mm_category[str.substr(0,1)[0]] = std::stoi(str.substr(2));
    }
    int i = 1;
    for(std::string& str : privacies){
        int result = (std::stoi(str.substr(0,4))*28*12) + ((std::stoi(str.substr(5,2))-1)*28) + std::stoi(str.substr(8));
        char c = str.substr(str.size()-1)[0];
        result += (mm_category[c]*28);
        //std::cout << day << " <> " << result << std::endl;
        if(day >= result) answer.push_back(i);
        i++;
    }
    return answer;
}

/**
 * 모든 월은 28일 밖에 없으므로,
 * yy -> 12 * 28 * yy
 * mm -> mm * 28
 * dd -> dd
 * total -> yy + mm + dd
 */

#endif //MAIN_CPP_KAKAO_150370_H
