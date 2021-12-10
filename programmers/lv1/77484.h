//
// Created by jjangchan on 2021-11-16.
// 77484 - 로또의 최고 순위와 최저 순위
//

#ifndef MAIN_CPP_77484_H
#define MAIN_CPP_77484_H
#include <string>
#include <vector>


std::vector<int> solution(std::vector<int> lottos, std::vector<int> win_nums) {
    int max = 7, min = 7;
    for(int i = 0; i < 6; ++i){
        if(lottos[i] == 0){
            max--;
            continue;
        }
        for(int j = 0; j < 6; ++j){
            if(lottos[i] == win_nums[j]){
                min--, max--;
                break;
            }
        }
    }
    std::vector<int> answer;
    answer.push_back((max == 7) ? 6 : max);
    answer.push_back((min == 7) ? 6 : min);
    return answer;
}


#endif //MAIN_CPP_77484_H
