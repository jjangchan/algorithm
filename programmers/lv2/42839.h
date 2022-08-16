//
// Created by jjangchan on 2022/08/16.
// 소수찾기
//

#ifndef MAIN_CPP_42839_H
#define MAIN_CPP_42839_H

#include <string>
#include <set>
#include <iostream>
#include <memory.h>

using namespace std;

std::set<int> s;
bool is[7];
bool not_prime[10000000] = {true, true, };

//173
void permutation(const std::string& numbers, const std::string& temp){

    for(int i = 0; i < numbers.size(); i++){
        if(!is[i]){
            is[i] = true;
            permutation(numbers,temp+numbers[i]);
            is[i] = false;
        }
    }
    if(temp.size() > 0) s.insert(std::stoi(temp));
}

void check_prime(const int len){
    for(int i = 2; i*i <= len; i++){
        if(!not_prime[i]){
            for(int j = i*i; j <= len; j += i ) not_prime[j] = true;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    permutation(numbers, "");
    check_prime(*(--s.end()));
    for(const auto& num : s) if(!not_prime[num]) answer++;
    return answer;
}

#endif //MAIN_CPP_42839_H
