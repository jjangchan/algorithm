//
// Created by jjangchan on 2023/08/28.
// 피로도 - 87964
//

#ifndef MAIN_CPP_87946_H
#define MAIN_CPP_87946_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;
int is[8];

int solution(int k, vector<vector<int>> dungeons) {
    auto play = [&](auto& re, int score)->int{
        int result = 0;
        for(int i = 0; i < dungeons.size(); i++){
            if(!is[i] && score >= dungeons[i][0]){
                is[i] = true;
                result = std::max(re(re, score-dungeons[i][1])+1, result);
                is[i] = false;
            }
        }

        return result;
    };
    return play(play, k);
}

#endif //MAIN_CPP_87946_H
