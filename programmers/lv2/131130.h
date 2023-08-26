//
// Created by jjangchan on 2023/08/20.
// 혼자 놀기의 달인 - 131130
//

#ifndef MAIN_CPP_131130_H
#define MAIN_CPP_131130_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int is_card[101];

int solution(vector<int> cards) {
    std::vector<int> answer;
    auto go = [&](auto& re, int index){
        if(is_card[index]) return 0;
        is_card[index]++;
        return re(re, cards[index-1])+1;
    };

    for(int i = 0; i < cards.size(); i++){
        if(is_card[cards[i]] == 0) answer.emplace_back(go(go, cards[i]));
    }
    std::sort(answer.begin(), answer.end(), greater<>());
    return answer.size() == 1 ? 0 : answer[0]*answer[1];
}

#endif //MAIN_CPP_131130_H
