//
// Created by jjangchan on 2023/12/18.
//

#ifndef MAIN_CPP_2023_12_18_H
#define MAIN_CPP_2023_12_18_H
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

std::vector<int> solution(std::vector<int> deck, int n){
    std::vector<int> temp;
    int index = 0;
    for(int i = 1; i <= n; i++){
        if(i != deck[index]) temp.push_back(i);
        else index++;
    }
    std::vector<int> result(temp.size(), 0xffff);
    std::vector<int> is(temp.size(), 1);

    auto go = [&](auto& loop, int cnt, int start, int end)->void {
        if(cnt == end) return;
        for(int i = start; i < end; i++) {
            is[i] = 0;
            loop(loop, cnt+1,i+1, end);
            is[i] = 1;
        }
        if(cnt == 0) {
            result[temp.size()-1] = 1;
        }else{
            std::vector<int> deck_result(deck.begin(), deck.end());
            for(int i = 0; i < end; i++){
                if(!is[i]) {
                    deck_result.push_back(temp[i]);
                }
            }
            std::sort(deck_result.begin(), deck_result.end());
            int sum = deck_result[0];
            for(int i = 1; i < deck_result.size(); i++){
                if(deck_result[i]-deck_result[i-1] != 1) sum += deck_result[i];
            }
            result[cnt-1] = std::min(result[cnt-1], sum);
        }
    };
    go(go, 0, 0,temp.size());
    return result;
}


#endif //MAIN_CPP_2023_12_18_H
