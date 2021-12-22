//
// Created by jjangchan on 2021-12-22.
//

#ifndef MAIN_CPP_42626_H
#define MAIN_CPP_42626_H

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    std::priority_queue<int, vector<int>, greater<int>> q_scoville(scoville.begin(), scoville.end());
    while(q_scoville.size() > 1){
        int score = q_scoville.top();
        if(score >= K) return answer;
        q_scoville.pop();
        score += (2*q_scoville.top());
        q_scoville.pop();
        q_scoville.push(score);
        answer++;
    }
    return q_scoville.top() >= K ? answer : -1;
}

#endif //MAIN_CPP_42626_H
