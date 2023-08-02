//
// Created by jjangchan on 2023/08/02.
// 택배 배달과 수거하기
//

#ifndef MAIN_CPP_150369_H
#define MAIN_CPP_150369_H

#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0, deli_cnt = 0, pick_cnt = 0;
    for(int i = n-1; i >= 0; i--){
        deli_cnt -= deliveries[i];
        pick_cnt -= pickups[i];
        std::cout << deli_cnt << "," << pick_cnt << std::endl;
        if(deli_cnt < 0 || pick_cnt < 0){
            long long weight = std::max(deli_cnt*-1, pick_cnt*-1);
            weight = (weight%cap) ? weight/cap+1 : weight/cap;
            std::cout << "weight >> " << weight << std::endl;
            deli_cnt += weight*cap;
            pick_cnt += weight*cap;
            std::cout << "after >> " << deli_cnt << " , " << pick_cnt << std::endl;
            answer += (weight*(i+1)*2);
            std::cout << "answer >> " << answer << std::endl;
        }
        std::cout << "================================================" << std::endl;
    }
    std::cout << answer << std::endl;
    return answer;
}

#endif //MAIN_CPP_150369_H
