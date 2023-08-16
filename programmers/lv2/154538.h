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
            if(nums.first%3 == 0) q.push({nums.first/3, nums.second+1}); // -- (1)
            if(nums.first%2 == 0) q.push({nums.first/2, nums.second+1}); // -- (2)
            q.push({nums.first-n, nums.second+1}); // -- (3)
        }

    }
    return -1;
}

/**
 *  BFS로 문제를 해결한다. y값을,
 *  (1) -- 3로 나누어 떨어지면 큐에 3을 나눈 몫을 큐에 저장한다.
 *  (2) -- 2로 나누어 떨어지면 큐에 2을 나눈 몫을 큐에 저장한다.
 *  (3) -- y-n 값을 큐에 저장한다.
 *
 *  [문제점]
 *  시간복잡도가 최악인 경우 O(3^n) 이므로 최적화된 방법론은 아니다.
 *  따라서 동적 계획법으로 해결하면 최적화 된다.
 *
[dp 로 해결한 에제 코드]
#include <string>
#include <vector>

using namespace std;

int dp[1000001];

int solution(int x, int y, int n) {
    int answer = 0;
    fill(dp,dp+1000001, 10000000);
    dp[x] = 0;

    for(int i = x; i <= y; i++){
        if(i+n <= y) dp[i+n] = min(dp[i+n],dp[i] + 1);
        if(i*2 <= y) dp[i*2] = min(dp[i*2], dp[i] + 1);
        if(i*3 <= y) dp[i*3] = min(dp[i*3], dp[i] + 1);
    }
    answer = dp[y];
    if(answer == 10000000) answer = -1;
    return answer;
}
 */

#endif //MAIN_CPP_154538_H
