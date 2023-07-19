//
// Created by jjangchan on 2023/07/19.
// 178870 - 연속된 부분 수열의 합
//

#ifndef MAIN_CPP_1778870_H
#define MAIN_CPP_1778870_H

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int sum = 0, begin = 0, i = 0;
    while(sequence[i] <= k && i < sequence.size()){
        sum += sequence[i];
        while(sum > k) sum -= sequence[begin++]; // -- (1)
        if(sum == k) if(answer.empty() || i-begin < answer[1]-answer[0]){ // -- (2)
            answer = {begin, i}; // -- (3)
        }
        i++;
    }
    return answer;
}

/**
 * 수열에 시작 포인터 begin 변수와 수열의 합 sum 변수를 저장해서 해결한다. 만약,
 * -- (1) sum이 k 보다 크다면 루프를 통해서 sum이 k값 보다 작을때 까지 begin을 증감하면서 빼주고
 * -- (2) sum 과 k가 같으면 answer에 begin 과 마지막 인덱스 i를 저장 하는데,
 * -- (3) 만약 answer에 값이 있다면 저장된 i와 begin 과 현재 i 와 begin 에 차이를 비교해서 차이값이 작은 i 와 begin 으로 저장한다.
 */

#endif //MAIN_CPP_1778870_H
