//
// Created by jjangchan on 2023/08/17.
// 연속 부분 수열 합의 개수
//

#ifndef MAIN_CPP_131701_H
#define MAIN_CPP_131701_H

#include <string>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int is[1000001];

int solution(vector<int> elements) {
    int answer = 0, sum = 0;
    std::vector<int> v_sum(elements.size(), 0);
    for(int i = 0; i < elements.size()-1; i++) for(int j = 0; j < elements.size(); j++){
        int index = ((j+i)%(int)elements.size());
        v_sum[j] += elements[index];
        if(is[v_sum[j]] == 0) is[v_sum[j]]++, answer++;
    }
    return (is[std::accumulate(elements.begin(), elements.end(), 0)] == 0) ? answer+1 : answer;
}

#endif //MAIN_CPP_131701_H
