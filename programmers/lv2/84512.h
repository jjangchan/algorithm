//
// Created by jjangchan on 2024/05/10.
// 84512 - 모음사전
//

#ifndef MAIN_CPP_84512_H
#define MAIN_CPP_84512_H

#include <iostream>
#include <vector>
#include <string>

int solution(std::string word) {
    std::string dict = "AEIOU";
    int max = 5;
    bool end = false;
    auto go = [&](auto& re, const std::string target)-> int{
        //std::cout << "in --> " << target << std::endl;
        if(end) return 0;
        if(target == word){
            end = true;
            return 0;
        }
        int cnt = 0;
        if(target.size() == max) return 0;
        for(int i = 0; i < max; i++)
            if(!end)
                cnt += re(re, target+dict[i])+1;
        return cnt;
    };
    return go(go, "");
}

#endif //MAIN_CPP_84512_H
