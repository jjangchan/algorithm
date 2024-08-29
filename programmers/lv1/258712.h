//
// Created by jjangchan on 2024/01/09.
// 카카오 가장 많이 받은 선물 - 258712
//

#ifndef MAIN_CPP_258712_H
#define MAIN_CPP_258712_H

#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int size = friends.size();
    std::map<std::string, int> indexs;
    std::vector<int> gift_index(size, 0);
    std::vector<std::vector<int>> gifts_table(size, std::vector<int>(size, 0));
    for(int i = 0; i < size; i++) indexs[friends[i]] = i;
    for(const auto& s : gifts){
        std::string l_str, r_str;
        std::istringstream iss(s);
        iss >> l_str >> r_str;
        int l_index = indexs[l_str], r_index = indexs[r_str];
        gift_index[l_index]++, gift_index[r_index]--;
        gifts_table[l_index][r_index]++;
    }
    std::vector<int> result(size, 0);
    for(int i = 0; i < size-1; i++) for(int j = i+1; j < size; j++){
            if(gifts_table[i][j] > gifts_table[j][i]) result[i]++;
            else if(gifts_table[i][j] < gifts_table[j][i]) result[j]++;
            else{
                if(gift_index[i] > gift_index[j]) result[i]++;
                else if(gift_index[i] < gift_index[j]) result[j]++;
            }
        }
    return *std::max_element(result.begin(), result.end());
}

#endif //MAIN_CPP_258712_H
