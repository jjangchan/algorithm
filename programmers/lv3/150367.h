//
// Created by jjangchan on 2024/09/24.
// 150367 - 표현 가능한 이진트리
//

#ifndef MAIN_CPP_150367_H
#define MAIN_CPP_150367_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    auto to_bi = [](std::size_t num) -> std::string{
        std::string str;
        while(num){
            char c = (num%2)+'0';
            str.push_back(c);
            num /= 2;
        }
        std::size_t chk = std::pow(2, (std::size_t)std::log2(str.size())+1)-1;
        for(std::size_t i = str.size(); i < chk; i++) str.push_back('0');
        std::reverse(str.begin(), str.end());
        return str;
    };

    auto dfs = [](auto& re, const std::string& str, const std::size_t idx, const int cnt)->int{
        if(cnt < 0) return 1;
        std::size_t next = std::pow(2, cnt);
        if(str[idx] == '0'){
            if(str[idx-next] == '1' || str[idx+next] == '1') return 0;
        }
        return re(re, str, idx-next, cnt-1) && re(re, str, idx+next, cnt-1);
    };


    for(const long long num : numbers){
        std::string b_num = to_bi(num);
        std::size_t cen = b_num.size()/2;
        int chk = b_num[cen] == '1';
        if(chk) chk = dfs(dfs, b_num, cen, (int)std::log2(cen));
        std::cout << b_num << "(" << num << ") : " << chk << std::endl;
        answer.push_back(chk);
    }

    return answer;
}

#endif //MAIN_CPP_150367_H
