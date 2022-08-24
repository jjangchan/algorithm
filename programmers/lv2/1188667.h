//
// Created by jjangchan on 2022/08/24.
// 두 큐 합 같게 만들기
//

#ifndef MAIN_CPP_1188667_H
#define MAIN_CPP_1188667_H

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void compare(int64_t & q1_sum, int64_t& q2_sum, std::queue<int>& q1, std::queue<int>& q2){
    int num = q1.front();
    q1_sum -= num;
    q2_sum += num;
    q1.pop(), q2.push(num);
}

int solution(vector<int> queue1, vector<int> queue2) {
    int64_t q1_sum = 0, q2_sum = 0, total_size = queue1.size() + queue2.size() + 3;
    std::queue<int> q1, q2;
    for(int i = 0; i < queue1.size(); i++) {
        q1.push(queue1[i]), q2.push(queue2[i]);
        q1_sum += queue1[i], q2_sum += queue2[i];
    }
    int64_t sum = q1_sum + q2_sum;
    sum /= 2;
    int count = 0;

    while(true){
        if(q1_sum == sum && q2_sum == sum) return count;
        if(total_size <= count || (q1_sum <= sum && q2_sum <= sum) ) return -1;
        if(q1_sum > q2_sum){
            compare(q1_sum, q2_sum, q1, q2);
            std::cout << "[R] " << q1_sum << "," << q2_sum << std::endl;
        }else{
            compare(q2_sum, q1_sum, q2, q1);
            std::cout << "[L] " << q1_sum << "," << q2_sum << std::endl;
        }

        count++;
    }
    return -1;
}

#endif //MAIN_CPP_1188667_H
