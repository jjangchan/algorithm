//
// Created by jjangchan on 2023/12/26.
// PCCP 기출문제 1번
//

#ifndef MAIN_CPP_250137_H
#define MAIN_CPP_250137_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health, current_time = 0;
    for(const auto& v : attacks){
        int differ = v[0]-current_time-1;
        int add_hp = bandage[1]*differ+((differ/bandage[0])*bandage[2]);
        std::cout << "add hp : " << add_hp << std::endl;
        answer = (answer+add_hp >= health) ? health : answer+add_hp;
        answer -= v[1];
        std::cout << "hp : " << answer << std::endl;
        current_time = v[0];
        if(answer <= 0) return -1;
    }
    return answer;
}

#endif //MAIN_CPP_250137_H
