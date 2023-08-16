//
// Created by jjangchan on 2023/08/10.
// 디펜스 게임 - 142085
//

#ifndef MAIN_CPP_142085_H
#define MAIN_CPP_142085_H

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer, sum = 0;
    std::priority_queue<int> pq;
    for(answer = 0; answer < enemy.size(); answer++){
        sum += enemy[answer];
        std::cout << "sum : " << sum << std::endl;
        pq.push(enemy[answer]);
        while(k > 0 && !pq.empty() && sum > n){
            std::cout << "pop : " << pq.top() << std::endl;
            sum -= pq.top(), pq.pop();
            std::cout << "(pop) sum : " << sum << std::endl;
            k--;
        }
        if(sum > n) break;
    }
    std::cout << answer << std::endl;
    return answer;
}

#endif //MAIN_CPP_142085_H
