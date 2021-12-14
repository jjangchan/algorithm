//
// Created by jjangchan on 2021-12-14.
// 이상한 문자 만들기
//

#ifndef MAIN_CPP_12930_H
#define MAIN_CPP_12930_H

#include <string>
#include <sstream>
#include <vector>

using namespace std;

std::string transform(std::string input){
    int count = 0;
    for(int i = 0; i < input.size(); i++){
        if(input[i] == ' ') count = -1;
        else if(count&1){
            if(input[i] >= 'A' && input[i] <= 'Z') input[i] |= 32;
        }else{
            if(input[i] >= 'a' && input[i] <= 'z') input[i] ^= 32;
        }
        count++;
    }
    return input;
}

string solution(string s) {
    return transform(s);
}

#endif //MAIN_CPP_12930_H
