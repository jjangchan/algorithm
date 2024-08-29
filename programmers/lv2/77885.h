//
// Created by jjangchan on 2024/06/17.
// 77885 - 2개 이하로 다른 비트
//

#ifndef MAIN_CPP_77885_H
#define MAIN_CPP_77885_H

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(const long long num : numbers){
        if(!(num&1)) answer.push_back(num+1);
        else{
            long long end = (static_cast<long long>(std::floor(std::log2(num))))+1;
            long long val = (num << 1)+1;
            for(long long i = 0; i <= end; i++){
                long long cal = num^(static_cast<long long>(3) << i);
                if(num < cal && cal < val) val = cal;
            }
            answer.push_back(val);
        }
    }
    for(auto i : answer) std::cout << i << " ";
    return answer;
}

#endif //MAIN_CPP_77885_H
