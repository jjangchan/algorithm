//
// Created by jjangchan on 2023/12/17.
//

#ifndef MAIN_CPP_2023_12_17_H
#define MAIN_CPP_2023_12_17_H

#include <iostream>
#include <string>
#include <stack>
/**
 *  Use Case
 *  1. 3(hi) -> hihihi
 *  2. 2(3(hi)co) -> hihihicohihihico
 *  3. 10(p) -> pppppppppp
 *  4. 2(2(hi)2(co))x2(bo) -> hihicocohihicocoxbobo
 */

std::string mul_connect(const std::string& str, int num){
    std::string result;
    while(num--) result.append(str);
    return result;
}

std::string solution(const std::string& compressed){
    std::string result;
    std::string inner;
    int is_inner = 0;
    std::string str_num;
    std::stack<std::string> multiple;

    for(const char& c : compressed){
        if(c >= 48 && c <= 57){ // num
            str_num.push_back(c);
        }else if(c >= 97 && c <= 122){ // alphabet(low)
            (is_inner) ? inner.push_back(c) : result.push_back(c);
        }else if(c == ')'){
            int num = std::stoi(multiple.top());
            is_inner = 0;
            multiple.pop();
            if(inner.empty()) result = mul_connect(result, num);
            else{
                inner = mul_connect(inner, num);
                result.append(inner);
                inner = "";
            }
        }else{
            multiple.push(str_num);
            is_inner = 1;
            str_num = "";
        }
    }
    return result;
}


#endif //MAIN_CPP_2023_12_17_H
