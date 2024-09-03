//
// Created by jjangchan on 2024/08/30.
// 17686 - 파일명 정렬
//

#ifndef MAIN_CPP_17686_H
#define MAIN_CPP_17686_H

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> files) {
    auto get_hnt = [](const std::string& file) -> std::vector<std::string>{
        std::vector<std::string> hnt(3);
        int seq  = 0;
        for(const char c : file){
            if(seq == 0) if(c >= '0' && c <= '9') seq++;
            if(seq == 1) if(!(c >= '0' && c <= '9')) seq++;
            hnt[seq].push_back(c);
        }
        std::transform(hnt[0].begin(), hnt[0].end(), hnt[0].begin(), ::tolower);
        return hnt;
    };

    std::stable_sort(files.begin(), files.end(), [&get_hnt](const std::string& a, const std::string& b) -> bool{
        std::vector<std::string> v_a = get_hnt(a);
        std::vector<std::string> v_b = get_hnt(b);
        if(v_a[0] < v_b[0]) return true;
        if(v_a[0] == v_b[0] && std::stoi(v_a[1]) < std::stoi(v_b[1])) return true;
        return false;
    });
    vector<string> answer(files.begin(), files.end());
    return answer;
}

#endif //MAIN_CPP_17686_H
