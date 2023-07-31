//
// Created by jjangchan on 2021-09-23.
// JadenCase 문자열 만들기
//

#ifndef ALGORITHM_12951_H
#define ALGORITHM_12951_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>


using namespace std;

string solution(string s) {
    string answer = s;
    if(answer[0] >= 'a' && answer[0] <= 'z')answer[0] ^= 32;
    for(int i = 1; i < answer.size(); i++){
        if(answer[i-1] == ' '){
            if(answer[i] >= 'a' && answer[i] <= 'z') answer[i] ^= 32;
            continue;
        }
        if(answer[i] >= 'A' && answer[i] <= 'Z')answer[i] |= 32;
    }
    std::cout << answer;
    return answer;
}

#endif //ALGORITHM_12951_H
