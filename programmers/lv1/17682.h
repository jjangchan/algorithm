//
// Created by jjangchan on 2021-12-13.
//

#ifndef MAIN_CPP_17682_H
#define MAIN_CPP_17682_H

#include <string>
#include <cmath>

using namespace std;

/** stringstream 사용법
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    stringstream ss(dartResult);

    int sum[3] = { 0, 0, 0 };
    int options[3] = { 1, 1, 1 };
    for (int i = 0; i < 3; i++) {
        int score;
        char bonus;
        char option;

        ss >> score; // 숫자까지 읽고

        bonus = ss.get(); // 다음 chart
        option = ss.get(); // 다음 chart

        if (option != '*' && option != '#') {
            ss.unget(); // option이 없다면 그 전의 get 취소
        }

        switch (bonus) {
        case 'S':
            sum[i] += pow(score, 1);
            break;
        case 'D':
            sum[i] += pow(score, 2);
            break;
        case 'T':
            sum[i] += pow(score, 3);
            break;
        default:
            break;
        }

        switch (option) {
        case '*':
            if (i > 0 && options[i - 1]) options[i - 1] *= 2;
            options[i] *= 2;
            break;
        case '#':
            options[i] = -options[i];
            break;
        default:
            break;
        }
    }

    return sum[0] * options[0] + sum[1] * options[1] + sum[2] * options[2];
}
 */

int GetPower(const char& c){
    switch (c) {
        case 'T' : return 3;
        case 'D' : return 2;
        default : return 1;
    }
}

int GetDigit(const std::string &s, const int index, bool &down){
    if(index >= 0 && isdigit(s[index])){
        down = true;
        return std::stoi(s.substr(index, 2));
    }
    return std::stoi(s.substr(index+1,1));
}

int solution(string dartResult) {
    int answer = 0;
    bool is_start = false;

    for(int i = dartResult.size()-1; i >= 0; i = i-2){
        bool down = false;
        if(dartResult[i] == '*'){
            int weight = (is_start) ? 4 : 2;
            int digit = GetDigit(dartResult, i-3, down);
            answer += std::pow(digit, GetPower(dartResult[i-1])) * weight;
            i = (down) ? i-2 : i-1;
            is_start = true;
        }else if(dartResult[i] == '#'){
            int weight = (is_start) ? 2 : 1;
            int digit = GetDigit(dartResult, i-3, down);
            answer -= std::pow(digit, GetPower(dartResult[i-1])) * weight;
            i = (down) ? i-2 : i-1;
            is_start = false;
        }else{
            int weight = (is_start) ? 2 : 1;
            int digit = GetDigit(dartResult, i-2, down);
            answer += std::pow(digit, GetPower(dartResult[i])) * weight;
            if(down) i--;
            is_start = false;
        }
    }
    return answer;
}

#endif //MAIN_CPP_17682_H
