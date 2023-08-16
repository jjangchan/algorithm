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
    std::sort(weights.begin(), weights.end()); // -- (1)
    std::vector<long long> dp(1001, 0); // -- (2)
    for(int i = 0; i < weights.size(); i++){
        if(!dp[weights[i]]){
            for(int j = i+1; j < weights.size(); j++){
                double pai = static_cast<double>(weights[j])/static_cast<double>(weights[i]);
                if(pai > 2.0) break; // -- (4)
                if(pai == proport[0] || pai == proport[1] || pai == proport[2] || pai == proport[3]) dp[weights[i]]++; // -- (3)
            }
        }else dp[weights[i]]--; // -- (5)
        answer += dp[weights[i]]; // -- (6)
    }
    return answer;
}

/**
 * weights에 중복된 값이 있으면 -1 씩 차감해서 결과값에 더해주면 되므로 sort 해서 문제를 해결한다.
 *
 * (1) -- weights를 오름차순으로 정렬
 * (2) -- 무게 값들에 균형을 이룬 결과값들을 보관하기 위해 vector를 0으로 초기화
 * (3) -- j/i 가 {1(1m, 1m), 1.5(3m, 2m), 1.3333(4m, 3m), 2(4m, 2m)}을 이루면 균형을 이루어져 있으므로,
 *        i에 해당하는 weights 값을 +1 한다.
 * (4) -- i를 제외한 모든 weight를 검사하되 j/i 가 2.0을 넘으면 비교할 필요 없으므로 해당 for문을 중단
 * (5) -- 만약 i에 weight 에 0이상에 결과값이 있으면 검증이 끝난 값이므로 -1을 해준다.
 * (6) -- 균형을 이룬 값에 결과를 지속적으로 answer에 누적한다
 *
 *
 *
[수학적으로 접근한 예제 코드]
#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<long long> arr(2001,0);
    for(const auto v : weights) arr[v]++;

    for(int i = 100; i <= 1000; ++i){
        if(arr[i] == 0) continue;

        // n(an+1)/2
        answer += arr[i]*(arr[i]-1) / 2;
        answer += arr[i] * arr[2 * i];

        if((i * 3) % 2 == 0) answer += arr[i] * arr[i * 3 / 2];
        if((i * 4) % 3 == 0) answer += arr[i] * arr[i * 4 / 3];
    }
    return answer;
}
 */

#endif //MAIN_CPP_152996_H
