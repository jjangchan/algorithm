//
// Created by jjangchan on 2023/07/31.
// 152996 - 시소 짝궁
//

#ifndef MAIN_CPP_152996_H
#define MAIN_CPP_152996_H

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

double proport[4] = {1.0, 3.0/2.0, 4.0/3.0, 2.0};

long long solution(vector<int> weights) {
    long long answer = 0;
    std::sort(weights.begin(), weights.end());
    std::vector<long long> dp(1001, -1);
    for(int i = 0; i < weights.size(); i++){
        if(dp[weights[i]] == -1){
            dp[weights[i]] = 0;
            for(int j = i+1; j < weights.size(); j++){
                double pai = static_cast<double>(weights[j])/static_cast<double>(weights[i]);
                if(pai > 2.0) break;
                if(pai == proport[0] || pai == proport[1] || pai == proport[2] || pai == proport[3]) dp[weights[i]]++;
            }
        }else if(dp[weights[i]] > 0) dp[weights[i]]--;
        answer += dp[weights[i]];
    }
    return answer;
}

#endif //MAIN_CPP_152996_H
