//
// Created by jjangchan on 2021-12-14.
// 문자열을 정수로 바꾸기
//

#ifndef MAIN_CPP_12925_H
#define MAIN_CPP_12925_H
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    //return std::stoi(s);
    int answer = 0, x = 1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '-') x = -1;
        else if(s[i] != '+'){
            answer *= 10;
            answer += s[i]-48;
        }
    }
    return answer*x;
}

#endif //MAIN_CPP_12925_H
