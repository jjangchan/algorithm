//
// Created by jjangchan on 2021-11-16.
// 81301 - 숫자 문자열과 영단어
//

#ifndef MAIN_CPP_81301_H
#define MAIN_CPP_81301_H

#include <string>
#include <vector>

char NumberToChar(std::string s){
    if(s == "zero") return 48;
    else if(s == "one") return 49;
    else if(s == "two") return 50;
    else if(s == "three") return 51;
    else if(s == "four") return 52;
    else if(s == "five") return 53;
    else if(s == "six") return 54;
    else if(s == "seven") return 55;
    else if(s == "eight") return 56;
    else if(s == "nine") return 57;
    return 1;
}

int solution(std::string s) {
    std::string answer = "";
    std::string str_number = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 48 && s[i] <= 57) answer.push_back(s[i]);
        else{
            str_number.push_back(s[i]);
            char number = NumberToChar(str_number);
            if(number != 1){
                answer.push_back(number);
                str_number = "";
            }
        }
    }
    return std::stoi(answer);
}

#endif //MAIN_CPP_81301_H
