//
// Created by jjangchan on 2021/10/11.
// 소수만들기
//

#ifndef MAIN_CPP_12977_H
#define MAIN_CPP_12977_H
#include <vector>
#include <iostream>
using namespace std;

bool IsPrime(const int num){
    for(int i = 2; i*i <= num; i++){
        if(num%i == 0)return false;
    }
    return true;
}

void Combination(const std::vector<int> &nums,
                 const int size,
                 const int max,
                 const int count,
                 int i,
                 int &answer){
    for(; i < nums.size(); i++){
        if(size == max){
            if(IsPrime(count+nums[i])) answer++;
        }
        else Combination(nums, size+1, max, count+nums[i], i+1, answer);
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    Combination(nums, 1, 3, 0, 0, answer);
    return answer;
}

#endif //MAIN_CPP_12977_H
