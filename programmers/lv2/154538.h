//
// Created by jjangchan on 2023/07/31.
// 숫자 변환하기 - 154538
//

#ifndef MAIN_CPP_154538_H
#define MAIN_CPP_154538_H

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    std::queue<std::pair<int,int>> q;
    q.push({y,0});
    while(!q.empty()){
        std::pair<int, int> nums = q.front();
        q.pop();
        if(nums.first == x) return nums.second;
        if(nums.first > x){
            if(nums.first%3 == 0) q.push({nums.first/3, nums.second+1});
            if(nums.first%2 == 0) q.push({nums.first/2, nums.second+1});
            q.push({nums.first-n, nums.second+1});
        }

    }
    return -1;
}

#endif //MAIN_CPP_154538_H
